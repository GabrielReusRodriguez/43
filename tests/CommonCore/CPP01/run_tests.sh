#!/usr/bin/env bash
# Runner de tests para src/CommonCore/CPP01
set -u

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${DIR}/../../.." && pwd)"
BASE="${ROOT}/src/CommonCore/CPP01"

pass=0
fail=0

ok() {
  echo "  OK  $*"
  pass=$((pass + 1))
}

ko() {
  echo "  FAIL $*"
  fail=$((fail + 1))
}

expect_contains() {
  local haystack="$1"
  local needle="$2"
  local label="$3"
  if echo "${haystack}" | grep -qF "${needle}"; then
    ok "${label}"
  else
    ko "${label}"
    echo "    missing: ${needle}"
  fi
}

expect_eq() {
  local got="$1"
  local want="$2"
  local label="$3"
  if [[ "${got}" == "${want}" ]]; then
    ok "${label}"
  else
    ko "${label}"
    echo "    got:  ${got}"
    echo "    want: ${want}"
  fi
}

echo "=== CPP01 tests ==="
echo "Dir: ${BASE}"
echo

echo "-- ex00 BraiiiiiiinnnzzzZ --"
if ! make -C "${BASE}/ex00" re >/dev/null; then
  ko "build ex00"
else
  ok "build ex00"
  out="$("${BASE}/ex00/zombie" 2>&1)"
  expect_contains "${out}" "Zombie heap: BraiiiiiiinnnzzzZ..." "announce heap"
  expect_contains "${out}" "Zombie stack: BraiiiiiiinnnzzzZ..." "announce stack"
  expect_contains "${out}" "Zombie heap destroyed" "dtor heap"
  expect_contains "${out}" "Zombie stack destroyed" "dtor stack"
fi

echo
echo "-- ex01 Moar brainz! --"
if ! make -C "${BASE}/ex01" re >/dev/null; then
  ko "build ex01"
else
  ok "build ex01"
  out="$(ASAN_OPTIONS=detect_leaks=0 "${BASE}/ex01/zombie" 2>&1)"
  count="$(echo "${out}" | grep -c 'ZzZz: BraiiiiiiinnnzzzZ...' || true)"
  expect_eq "${count}" "10" "10 announces"
  dcount="$(echo "${out}" | grep -c 'ZzZz destroyed' || true)"
  expect_eq "${dcount}" "10" "10 destructors"
fi

echo
echo "-- ex02 HI THIS IS BRAIN --"
if ! make -C "${BASE}/ex02" re >/dev/null; then
  ko "build ex02"
else
  ok "build ex02"
  out="$("${BASE}/ex02/ex02" 2>&1)"
  addr_line="$(echo "${out}" | grep 'Memory Address of string:' | awk '{print $NF}')"
  ptr_line="$(echo "${out}" | grep 'Memory Address held by stringPTR' | awk '{print $NF}')"
  ref_line="$(echo "${out}" | grep 'Memory Address held by stringREF' | awk '{print $NF}')"
  if [[ -n "${addr_line}" && "${addr_line}" == "${ptr_line}" && "${ptr_line}" == "${ref_line}" ]]; then
    ok "mismas direcciones string/PTR/REF"
  else
    ko "mismas direcciones string/PTR/REF"
  fi
  expect_contains "${out}" "Value of string: HI THIS IS BRAIN" "valor string"
  expect_contains "${out}" "Value pointed by stringPTR: HI THIS IS BRAIN" "valor PTR"
  expect_contains "${out}" "Value pointed by stringREF: HI THIS IS BRAIN" "valor REF"
fi

echo
echo "-- ex03 Unnecessary violence --"
if ! make -C "${BASE}/ex03" re >/dev/null; then
  ko "build ex03"
else
  ok "build ex03"
  out="$(ASAN_OPTIONS=detect_leaks=0 "${BASE}/ex03/ex03" 2>&1)"
  expect_contains "${out}" "Bob attacks with their crude spiked club" "Bob arma inicial"
  expect_contains "${out}" "Bob attacks with their some other type of club" "Bob arma cambiada"
  expect_contains "${out}" "Jim attacks with their crude spiked club" "Jim arma inicial"
  expect_contains "${out}" "Jim attacks with their some other type of club" "Jim arma cambiada"
fi

echo
echo "-- ex04 Sed is for losers --"
if ! make -C "${BASE}/ex04" re >/dev/null; then
  ko "build ex04"
else
  ok "build ex04"
  tmp="$(mktemp -d)"
  printf 'hello world\n\nfoo bar\n' >"${tmp}/in.txt"
  if "${BASE}/ex04/ex04" "${tmp}/in.txt" "foo" "baz" >/dev/null; then
    ok "exit 0 en replace OK"
  else
    ko "exit 0 en replace OK"
  fi
  got="$(cat "${tmp}/in.txt.replace")"
  want="$(printf 'hello world\n\nbaz bar')"
  expect_eq "${got}" "${want}" "contenido .replace (líneas vacías + replace)"
  if ! "${BASE}/ex04/ex04" "${tmp}/in.txt" "" "x" >/dev/null 2>&1; then
    ok "rechaza s1 vacío"
  else
    ko "rechaza s1 vacío"
  fi
  if ! "${BASE}/ex04/ex04" >/dev/null 2>&1; then
    ok "rechaza argc incorrecto"
  else
    ko "rechaza argc incorrecto"
  fi
  if ! "${BASE}/ex04/ex04" "${tmp}/nope.txt" "a" "b" >/dev/null 2>&1; then
    ok "rechaza fichero inexistente"
  else
    ko "rechaza fichero inexistente"
  fi
  rm -rf "${tmp}"
fi

echo
echo "-- ex05 Harl 2.0 --"
if ! make -C "${BASE}/ex05" re >/dev/null; then
  ko "build ex05"
else
  ok "build ex05"
  out="$("${BASE}/ex05/ex05" 2>&1)"
  expect_contains "${out}" "DEBUG" "nivel DEBUG"
  expect_contains "${out}" "INFO" "nivel INFO"
  expect_contains "${out}" "WARNING" "nivel WARNING"
  expect_contains "${out}" "ERROR" "nivel ERROR"
fi

echo
echo "-- ex06 harlFilter --"
if ! make -C "${BASE}/ex06" re >/dev/null; then
  ko "build ex06"
else
  ok "build ex06"
  out="$("${BASE}/ex06/harlFilter" WARNING 2>&1)"
  expect_contains "${out}" "[ WARNING ]" "WARNING visible"
  expect_contains "${out}" "[ ERROR ]" "ERROR visible (nivel superior)"
  if echo "${out}" | grep -qF '[ DEBUG ]' || echo "${out}" | grep -qF '[ INFO ]'; then
    ko "WARNING no debe mostrar DEBUG/INFO"
  else
    ok "WARNING no muestra DEBUG/INFO"
  fi
  out="$("${BASE}/ex06/harlFilter" "I am not sure how tired I am today..." 2>&1)"
  expect_contains "${out}" "[ Probably complaining about insignificant problems ]" "nivel inválido"
  if ! "${BASE}/ex06/harlFilter" >/dev/null 2>&1; then
    ok "rechaza sin argumentos"
  else
    ko "rechaza sin argumentos"
  fi
fi

echo
echo "Resultado: ${pass} OK, ${fail} FAIL"
if [[ "${fail}" -gt 0 ]]; then
  exit 1
fi
exit 0
