#!/usr/bin/env bash
# Runner de builds y smoke-tests para src/Piscina
set -u

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
PISCINA_DIR="${ROOT_DIR}/src/Piscina"
TIMEOUT_SECS="${TIMEOUT_SECS:-5}"

ok=0
fail=0
skip=0
run_ok=0
run_fail=0

red() { printf '\033[31m%s\033[0m\n' "$*"; }
green() { printf '\033[32m%s\033[0m\n' "$*"; }
yellow() { printf '\033[33m%s\033[0m\n' "$*"; }

has_timeout() { command -v timeout >/dev/null 2>&1; }

run_binary() {
  local bin="$1"
  local dir="$2"
  shift 2
  if has_timeout; then
    (cd "$dir" && timeout "${TIMEOUT_SECS}" "$bin" "$@" >/dev/null 2>&1)
  else
    (cd "$dir" && "$bin" "$@" >/dev/null 2>&1)
  fi
}

echo "=== Piscina build & smoke tests ==="
echo "Root: ${PISCINA_DIR}"
echo

while IFS= read -r makefile; do
  dir="$(dirname "$makefile")"
  rel="${dir#${PISCINA_DIR}/}"

  # Skip nested experimental variants if any appear later
  case "$rel" in
    */v1/*|*/recursive/*) continue ;;
  esac

  if ! make -C "$dir" all >/tmp/piscina_make.out 2>&1; then
    red "BUILD FAIL  ${rel}"
    sed -n '1,8p' /tmp/piscina_make.out | sed 's/^/  /'
    fail=$((fail + 1))
    continue
  fi
  green "BUILD OK    ${rel}"
  ok=$((ok + 1))

  # Prefer known binary names
  bin=""
  for candidate in \
      "${dir}/test_$(basename "$dir").out" \
      "${dir}/"*.out \
      "${dir}/rush-00" \
      "${dir}/do-op.out" \
      "${dir}/ft_cat.out" \
      "${dir}/ft_tail.out" \
      "${dir}/ft_display_file.out"
  do
    # Expand globs carefully
    if [ -x "$candidate" ] 2>/dev/null; then
      bin="$candidate"
      break
    fi
  done

  # Glob fallback for *.out
  if [ -z "$bin" ]; then
    shopt -s nullglob
    outs=("${dir}"/*.out)
    shopt -u nullglob
    if [ ${#outs[@]} -gt 0 ] && [ -x "${outs[0]}" ]; then
      bin="${outs[0]}"
    fi
  fi

  if [ -z "$bin" ]; then
    # Libraries / headers / scripts: no runnable binary
    if [ -f "${dir}/libft.a" ] || [ -f "${dir}/ft.h" ] || [ -f "${dir}/libft_creator.sh" ]; then
      yellow "SKIP RUN   ${rel} (artefacto sin main)"
      skip=$((skip + 1))
      continue
    fi
    yellow "SKIP RUN   ${rel} (sin binario)"
    skip=$((skip + 1))
    continue
  fi

  args=()
  case "$rel" in
    C06/ex00) args=() ;;
    C06/ex01|C06/ex02|C06/ex03) args=(b a c) ;;
    C07/ex04) args=(42) ;;
    C08/ex04|C08/ex05) args=(hola mundo 42) ;;
    C10/ex00)
      if [ -f "${dir}/examples/test.txt" ]; then
        args=("${dir}/examples/test.txt")
      fi
      ;;
    C10/ex01)
      if [ -f "${dir}/examples/test.txt" ]; then
        args=("${dir}/examples/test.txt")
      fi
      ;;
    C10/ex02)
      if [ -f "${dir}/examples/test.txt" ]; then
        args=(-c 5 "${dir}/examples/test.txt")
      fi
      ;;
    C11/ex05)
      args=(1 + 2)
      ;;
    C11/ex07)
      args=(zebra apple mango)
      ;;
    C12/ex00)
      args=(hello)
      ;;
    C12/*)
      args=(zeta alpha beta gamma)
      ;;
  esac

  if run_binary "$bin" "$dir" "${args[@]+"${args[@]}"}"; then
    green "RUN OK     ${rel} ($(basename "$bin"))"
    run_ok=$((run_ok + 1))
  else
    red "RUN FAIL   ${rel} ($(basename "$bin"))"
    run_fail=$((run_fail + 1))
  fi
done < <(find "${PISCINA_DIR}" -path '*/ex*/Makefile' | sort)

echo
echo "=== Shell smoke (scripts existen y son ejecutables) ==="
shell_ok=0
shell_fail=0
while IFS= read -r script; do
  rel="${script#${PISCINA_DIR}/}"
  if [ -x "$script" ] || head -1 "$script" | grep -q '^#!'; then
    green "SCRIPT OK  ${rel}"
    shell_ok=$((shell_ok + 1))
  else
    yellow "SCRIPT     ${rel} (sin shebang/exec)"
    shell_ok=$((shell_ok + 1))
  fi
done < <(find "${PISCINA_DIR}/Shell00" "${PISCINA_DIR}/Shell01" -type f \( -name '*.sh' -o -name 'midLS' -o -name 'clean' \) | sort)

echo
echo "=== Resumen ==="
echo "Build OK:   ${ok}"
echo "Build FAIL: ${fail}"
echo "Run OK:     ${run_ok}"
echo "Run FAIL:   ${run_fail}"
echo "Run SKIP:   ${skip}"
echo "Shell OK:   ${shell_ok}"

if [ "$fail" -gt 0 ] || [ "$run_fail" -gt 0 ]; then
  exit 1
fi
exit 0
