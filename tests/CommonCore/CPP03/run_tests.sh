#!/usr/bin/env bash
# Runner de tests para src/CommonCore/CPP03
set -u

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${DIR}/../../.." && pwd)"
BASE="${ROOT}/src/CommonCore/CPP03"

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

echo "=== CPP03 tests ==="
echo "Dir: ${BASE}"
echo

echo "-- ex00 ClapTrap --"
if ! make -C "${BASE}/ex00" re >/dev/null; then
  ko "build ex00"
else
  ok "build ex00"
  out="$("${BASE}/ex00/ex00" 2>&1)"
  expect_contains "${out}" "ClapTrap Constructor of Gabriel called." "ctor"
  expect_contains "${out}" "ClapTrap Gabriel attacks target" "attack"
  expect_contains "${out}" "is repaired, getting 2 points healed!" "repair vivo"
  # Tras morir, repair/attack deben fallar (no revivir)
  dead_repairs="$(echo "${out}" | grep -c 'is repaired' || true)"
  expect_eq "${dead_repairs}" "1" "solo 1 repair (no revive muerto)"
  expect_contains "${out}" "ClapTrap Gabriel is dead." "muerto no actúa"
  expect_contains "${out}" "ClapTrap Destructor of Gabriel called." "dtor"
fi

echo
echo "-- ex01 ScavTrap --"
if ! make -C "${BASE}/ex01" re >/dev/null; then
  ko "build ex01"
else
  ok "build ex01"
  out="$("${BASE}/ex01/ex01" 2>&1)"
  expect_contains "${out}" "ClapTrap Constructor of Gabriel called." "base ctor primero"
  expect_contains "${out}" "ScavTrap Constructor of Gabriel called." "derived ctor"
  expect_contains "${out}" "ScavTrap Gabriel attacks target, causing 20 points of damage!" "attack Scav"
  expect_contains "${out}" "ScavTrap is now in Gate keeper mode." "guardGate"
  # destrucción en orden inverso
  dtor_order="$(echo "${out}" | grep -E 'Destructor' | tr '\n' '|')"
  if echo "${dtor_order}" | grep -q 'ScavTrap Destructor.*ClapTrap Destructor'; then
    ok "dtor ScavTrap antes que ClapTrap"
  else
    ko "dtor ScavTrap antes que ClapTrap"
    echo "    got: ${dtor_order}"
  fi
fi

echo
echo "-- ex02 FragTrap --"
if ! make -C "${BASE}/ex02" re >/dev/null; then
  ko "build ex02"
else
  ok "build ex02"
  out="$("${BASE}/ex02/ex02" 2>&1)"
  expect_contains "${out}" "ClapTrap Constructor of Gabriel called." "base ctor primero"
  expect_contains "${out}" "FragTrap Constructor of Gabriel called." "derived ctor"
  expect_contains "${out}" "causing 30 points of damage!" "damage 30"
  expect_contains "${out}" "request highFive!" "highFivesGuys"
  dtor_order="$(echo "${out}" | grep -E 'Destructor' | tr '\n' '|')"
  if echo "${dtor_order}" | grep -q 'FragTrap Destructor.*ClapTrap Destructor'; then
    ok "dtor FragTrap antes que ClapTrap"
  else
    ko "dtor FragTrap antes que ClapTrap"
  fi
fi

echo
echo "-- ex03 DiamondTrap --"
if ! make -C "${BASE}/ex03" re >/dev/null; then
  ko "build ex03"
else
  ok "build ex03"
  out="$("${BASE}/ex03/ex03" 2>&1)"
  expect_contains "${out}" "DiamondTrap name: Gabriel." "whoAmI diamond"
  expect_contains "${out}" "ClapTrap name: Gabriel_clap_name." "whoAmI clap"
  expect_contains "${out}" "HP: 100" "HP FragTrap"
  expect_contains "${out}" "EP: 50" "EP ScavTrap"
  expect_contains "${out}" "AD: 30" "AD FragTrap"
  expect_contains "${out}" "ScavTrap Gabriel_clap_name attacks target" "attack ScavTrap"
  expect_contains "${out}" "Gate keeper mode" "guardGate heredado"
  expect_contains "${out}" "request highFive!" "highFivesGuys heredado"
  # copy conserva _name
  whoami_count="$(echo "${out}" | grep -c 'DiamondTrap name: Gabriel.' || true)"
  expect_eq "${whoami_count}" "2" "copy whoAmI conserva _name"
fi

echo
echo "Resultado: ${pass} OK, ${fail} FAIL"
if [[ "${fail}" -gt 0 ]]; then
  exit 1
fi
exit 0
