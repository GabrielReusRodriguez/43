#!/usr/bin/env bash
# Runner de tests para src/CommonCore/push_swap
set -u

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${DIR}/../../.." && pwd)"
PROJ="${ROOT}/src/CommonCore/push_swap"
PS="${PROJ}/push_swap"
CHK="${PROJ}/checkers/checker_linux"

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

expect_checker_ok() {
  local args="$1"
  local label="${2:-$args}"
  local chk ops

  chk="$("${PS}" ${args} 2>/dev/null | "${CHK}" ${args} 2>/dev/null || true)"
  ops="$("${PS}" ${args} 2>/dev/null | grep -cE '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$' || true)"
  if [[ "${chk}" == "OK" ]]; then
    ok "sort [${label}] → OK (ops=${ops})"
  else
    ko "sort [${label}] → checker='${chk}' (ops=${ops})"
  fi
}

expect_checker_not_ok() {
  local args="$1"
  local label="${2:-$args}"
  local chk

  chk="$("${PS}" ${args} 2>/dev/null | "${CHK}" ${args} 2>/dev/null || true)"
  if [[ "${chk}" != "OK" ]]; then
    ok "unsupported [${label}] → no OK (esperado; chk='${chk}')"
  else
    ko "unsupported [${label}] → OK inesperado"
  fi
}

echo "=== push_swap tests ==="
echo "Dir: ${PROJ}"
echo

if [[ ! -x "${CHK}" ]]; then
  echo "BUILD FAIL: falta ${CHK}"
  exit 1
fi

if ! make -C "${PROJ}" re; then
  echo "BUILD FAIL"
  exit 1
fi

if [[ ! -x "${PS}" ]]; then
  echo "BUILD FAIL: no se generó ${PS}"
  exit 1
fi

echo
echo "-- n=3 (todas las permutaciones) --"
for args in "1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1"; do
  expect_checker_ok "${args}"
done

echo
echo "-- n=5 (muestras) --"
for args in "4 67 3 87 23" "5 4 3 2 1" "1 2 3 4 5" "2 1 3 4 5" "3 1 4 2 5"; do
  expect_checker_ok "${args}"
done

echo
echo "-- tamaños no soportados (comportamiento actual) --"
expect_checker_not_ok "4 3 2 1" "n=4"
expect_checker_not_ok "6 5 4 3 2 1" "n=6"

echo
echo "-- build / binario --"
ok "compiló push_swap"

echo
echo "=== resumen: ${pass} ok, ${fail} fail ==="
if [[ "${fail}" -gt 0 ]]; then
  echo "TEST FAIL"
  exit 1
fi
echo "TEST OK"
exit 0
