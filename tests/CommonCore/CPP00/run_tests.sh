#!/usr/bin/env bash
# Runner de tests para src/CommonCore/CPP00
set -u

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${DIR}/../../.." && pwd)"
BASE="${ROOT}/src/CommonCore/CPP00"

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

echo "=== CPP00 tests ==="
echo "Dir: ${BASE}"
echo

echo "-- ex00 megaphone --"
if ! make -C "${BASE}/ex00" re >/dev/null; then
  ko "build ex00"
else
  ok "build ex00"
  expect_eq "$("${BASE}/ex00/megaphone")" \
    '* LOUD AND UNBEARABLE FEEDBACK NOISE *' \
    "sin args"
  expect_eq "$("${BASE}/ex00/megaphone" "shhhhh... I think the students are asleep...")" \
    'SHHHHH... I THINK THE STUDENTS ARE ASLEEP...' \
    "un argumento"
  expect_eq "$("${BASE}/ex00/megaphone" Damnit " ! " "Sorry students, I thought this thing was off.")" \
    'DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.' \
    "varios argumentos"
fi

echo
echo "-- ex01 phonebook --"
if ! make -C "${BASE}/ex01" re >/dev/null; then
  ko "build ex01"
else
  ok "build ex01"
  out="$(printf 'ADD\nAda\nLovelace\nLady\n123\nSecret\nSEARCH\n0\nEXIT\n' | "${BASE}/ex01/phonebook")"
  if echo "${out}" | grep -q 'Ada' && echo "${out}" | grep -q 'Lovelace' && echo "${out}" | grep -q 'darkest secret: Secret'; then
    ok "ADD + SEARCH contacto"
  else
    ko "ADD + SEARCH contacto"
  fi
  out="$(printf 'ADD\n\nEXIT\n' | "${BASE}/ex01/phonebook")"
  if echo "${out}" | grep -q 'empty fields'; then
    ok "rechaza campo vacío"
  else
    ko "rechaza campo vacío"
  fi
  out="$(printf 'ADD\nVeryLongFirstName\nVeryLongLastName\nNickLongXX\n999\nSec\nSEARCH\n0\nEXIT\n' | "${BASE}/ex01/phonebook")"
  if echo "${out}" | grep -q 'VeryLongF\.' && echo "${out}" | grep -q 'first name: VeryLongFirstName'; then
    ok "truncado a 10 columnas con '.'"
  else
    ko "truncado a 10 columnas con '.'"
  fi
fi

echo
echo "-- ex02 Account --"
if ! make -C "${BASE}/ex02" re >/dev/null; then
  ko "build ex02"
else
  ok "build ex02"
  got="$(mktemp)"
  exp="$(mktemp)"
  "${BASE}/ex02/account" | sed -E 's/\[[0-9_]+\]//' >"${got}"
  sed -E 's/\[[0-9_]+\]//' "${BASE}/ex02/19920104_091532.log" >"${exp}"
  if diff -q "${exp}" "${got}" >/dev/null; then
    ok "log vs 19920104_091532.log (ignorando timestamp)"
  else
    ko "log vs 19920104_091532.log"
    diff -u "${exp}" "${got}" | head -40
  fi
  rm -f "${got}" "${exp}"
fi

echo
echo "Resultado: ${pass} OK, ${fail} FAIL"
if [[ "${fail}" -gt 0 ]]; then
  exit 1
fi
exit 0
