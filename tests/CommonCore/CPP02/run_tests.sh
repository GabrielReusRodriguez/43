#!/usr/bin/env bash
# Runner de tests para src/CommonCore/CPP02
set -u

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${DIR}/../../.." && pwd)"
BASE="${ROOT}/src/CommonCore/CPP02"

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

echo "=== CPP02 tests ==="
echo "Dir: ${BASE}"
echo

echo "-- ex00 Orthodox Canonical Form --"
if ! make -C "${BASE}/ex00" re >/dev/null; then
  ko "build ex00"
else
  ok "build ex00"
  out="$("${BASE}/ex00/ex00" 2>&1)"
  expect_contains "${out}" "Default constructor called" "default ctor"
  expect_contains "${out}" "Copy constructor called" "copy ctor"
  expect_contains "${out}" "Copy assignment operator called" "copy assignment"
  expect_contains "${out}" "getRawBits member function called" "getRawBits"
  expect_contains "${out}" "Destructor called" "destructor"
  zeros="$(echo "${out}" | grep -c '^0$' || true)"
  expect_eq "${zeros}" "3" "tres raw bits a 0"
  if echo "${out}" | grep -q 'setRawBits member function called'; then
    ko "setRawBits no debe loguear"
  else
    ok "setRawBits sin log extra"
  fi
fi

echo
echo "-- ex01 fixed-point useful --"
if ! make -C "${BASE}/ex01" re >/dev/null; then
  ko "build ex01"
else
  ok "build ex01"
  out="$("${BASE}/ex01/ex01" 2>&1)"
  expect_contains "${out}" "a is 1234.43" "a float"
  expect_contains "${out}" "b is 10" "b float"
  expect_contains "${out}" "c is 42.4219" "c float"
  expect_contains "${out}" "d is 10" "d float"
  expect_contains "${out}" "a is 1234 as integer" "a int"
  expect_contains "${out}" "b is 10 as integer" "b int"
  expect_contains "${out}" "c is 42 as integer" "c int"
  expect_contains "${out}" "d is 10 as integer" "d int"
  expect_contains "${out}" "Float constructor called" "float ctor"
  expect_contains "${out}" "Int constructor called" "int ctor"
fi

echo
echo "-- ex02 operators --"
if ! make -C "${BASE}/ex02" re >/dev/null; then
  ko "build ex02"
else
  ok "build ex02"
  out="$("${BASE}/ex02/ex02" 2>&1)"
  mapfile -t lines < <(echo "${out}")
  expect_eq "${lines[0]:-}" "0" "a inicial"
  expect_eq "${lines[1]:-}" "0.00390625" "++a"
  expect_eq "${lines[2]:-}" "0.00390625" "a tras pre"
  expect_eq "${lines[3]:-}" "0.00390625" "a++"
  expect_eq "${lines[4]:-}" "0.0078125" "a tras post"
  expect_eq "${lines[5]:-}" "10.1016" "b = 5.05*2"
  expect_eq "${lines[6]:-}" "10.1016" "Fixed::max"
fi

echo
echo "-- ex03 BSP --"
if ! make -C "${BASE}/ex03" re >/dev/null; then
  ko "build ex03"
else
  ok "build ex03"
  out="$("${BASE}/ex03/ex03" 2>&1)"
  expect_contains "${out}" "outside: 0" "punto fuera"
  expect_contains "${out}" "inside:  1" "punto dentro"
  expect_contains "${out}" "vertex:  0" "vértice = false"
  expect_contains "${out}" "edge:    0" "arista = false"
fi

echo
echo "Resultado: ${pass} OK, ${fail} FAIL"
if [[ "${fail}" -gt 0 ]]; then
  exit 1
fi
exit 0
