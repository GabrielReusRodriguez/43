#!/usr/bin/env bash
# Runner de tests para src/OutherCore/libasm
set -u

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${DIR}/../../.." && pwd)"
BASE="${ROOT}/src/OutherCore/libasm"
TEST_DIR="${BASE}/test"

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

run_bin() {
  local name="$1"
  shift
  local bin="${TEST_DIR}/bin/${name}"
  if [[ ! -x "${bin}" ]]; then
    ko "missing ${name}"
    return 1
  fi
  local out
  if ! out="$("${bin}" "$@" 2>&1)"; then
    ko "run ${name} (exit $?)"
    echo "${out}" | sed 's/^/    /'
    return 1
  fi
  printf '%s\n' "${out}"
  return 0
}

echo "=== libasm tests ==="
echo "Dir: ${BASE}"
echo

echo "-- build libasm.a + tests --"
if ! make -C "${BASE}" re >/dev/null 2>&1; then
  ko "build libasm.a"
else
  ok "build libasm.a"
fi
if ! make -C "${TEST_DIR}" re >/dev/null 2>&1; then
  ko "build tests"
else
  ok "build tests"
fi
echo

echo "-- mandatory --"
out="$(run_bin test_strlen)" && {
  expect_contains "${out}" "len: 0" "strlen vacío"
  expect_contains "${out}" "len: 11" "strlen Hola mundo"
}

out="$(run_bin test_strcpy)" && {
  expect_contains "${out}" "ft_strcpy : 	src: _Hola mundo!_ 	dest: _Hola mundo!_" "strcpy copia"
  expect_contains "${out}" "ft_strcpy : 	src: __ 	dest: __" "strcpy vacío"
}

out="$(run_bin test_strcmp)" && {
  expect_contains "${out}" "ft test 	s1 __ s2 __ ret 0" "strcmp iguales vacíos"
  expect_contains "${out}" "ft test 	s1 _Gabriel_ s2 _Gabriel_ ret 0" "strcmp iguales"
  # Signo de la diferencia (glibc no garantiza a -1/0/1)
  if echo "${out}" | grep -q 's1 __ s2 _Gabriel_ ret -'; then
    ok "strcmp vacío < Gabriel"
  else
    ko "strcmp vacío < Gabriel"
  fi
}

out="$(run_bin test_write)" && {
  expect_contains "${out}" "ft_write res: 11" "write OK"
  expect_contains "${out}" "ft_write res: -1 errno 9" "write errno EBADF"
  expect_contains "${out}" "ft_write res: 0 errno 0" "write count 0"
}

# test_read abre src/test_read.c relativo al cwd del test/
(
  cd "${TEST_DIR}" || exit 1
  if out="$(./bin/test_read 2>&1)"; then
    expect_contains "${out}" "ft_read buffer" "read buffer"
    expect_contains "${out}" "ft_read buffer __ ret -1, errno 9" "read errno EBADF"
    # Misma longitud que read()
    r_ret="$(echo "${out}" | sed -n 's/^ read buffer .* ret \([-0-9]*\)$/\1/p' | head -1)"
    f_ret="$(echo "${out}" | sed -n 's/^ft_read buffer .* ret \([-0-9]*\)$/\1/p' | head -1)"
    expect_eq "${f_ret}" "${r_ret}" "read ret == ft_read ret"
  else
    ko "run test_read"
  fi
)

out="$(run_bin test_strdup)" && {
  expect_contains "${out}" "ft_strdup:" "strdup básico"
  expect_contains "${out}" "_HOla mundo!_" "strdup contenido"
}

echo
echo "-- bonus --"
out="$(run_bin test_ft_atoi_base)" && {
  expect_contains "${out}" "_123_ int 123" "atoi_base decimal"
  expect_contains "${out}" "_-123_ int -123" "atoi_base negativo"
  expect_contains "${out}" "_10_ int 8" "atoi_base octal"
  expect_contains "${out}" "_AB_ int 171" "atoi_base hex"
  expect_contains "${out}" "_Z_ int 0" "atoi_base inválido"
}

out="$(run_bin test_ft_list_push_front)" && {
  expect_contains "${out}" "_Adios mundo!_" "push_front cabeza"
  expect_contains "${out}" "_Hola mundo!_" "push_front cola"
}

out="$(run_bin test_ft_list_size)" && {
  expect_contains "${out}" "Size : 0" "list_size 0"
  expect_contains "${out}" "Size : 1" "list_size 1"
  expect_contains "${out}" "Size : 2" "list_size 2"
}

out="$(run_bin test_ft_list_sort)" && {
  # Primer caso: Adios antes que Hola
  block="$(echo "${out}" | awk '/DEBUG List/{c++; if(c==1) p=1} p; /END DEBUG/{if(c==1) exit}')"
  expect_contains "${block}" "_Adios mundo!_" "sort Adios primero"
  expect_contains "${block}" "_Hola mundo!_" "sort Hola segundo"
}

out="$(run_bin test_ft_list_remove_if)" && {
  # Tras borrar único nodo → EMPTY (segundo bloque)
  expect_contains "${out}" "EMPTY" "remove_if lista vacía / único nodo"
  expect_contains "${out}" "_Adios mundo!_" "remove_if conserva no coincidentes"
  expect_contains "${out}" "_Hola mundo!2_" "remove_if no borra parcial"
}

echo
echo "=== Resultado: ${pass} OK, ${fail} FAIL ==="
if [[ "${fail}" -ne 0 ]]; then
  exit 1
fi
exit 0
