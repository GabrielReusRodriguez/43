#!/usr/bin/env bash
# Runner de tests para src/CommonCore/CPP04
set -u

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${DIR}/../../.." && pwd)"
BASE="${ROOT}/src/CommonCore/CPP04"

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

expect_not_contains() {
  local haystack="$1"
  local needle="$2"
  local label="$3"
  if echo "${haystack}" | grep -qF "${needle}"; then
    ko "${label}"
    echo "    unexpected: ${needle}"
  else
    ok "${label}"
  fi
}

echo "=== CPP04 tests ==="
echo "Dir: ${BASE}"
echo

echo "-- ex00 Polymorphism --"
if ! make -C "${BASE}/ex00" re >/dev/null; then
  ko "build ex00"
else
  ok "build ex00"
  out="$("${BASE}/ex00/ex00" 2>&1)"
  expect_contains "${out}" "dog " "type dog"
  expect_contains "${out}" "cat " "type cat"
  expect_contains "${out}" "Meu! Meu!" "Cat makeSound"
  expect_contains "${out}" "BUP! BUP!" "Dog makeSound"
  # Sin virtual: WrongCat vía WrongAnimal* → sonido de WrongAnimal
  expect_contains "${out}" "MakeSound of a generic Wronganimal." "Wrong* sin virtual"
  expect_not_contains "${out}" "Wrong Meu! Meu!" "no llama WrongCat vía base"
  expect_contains "${out}" "WrongAnimal Default Destructor called." "delete WrongCat vía base"
fi

echo
echo "-- ex01 Brain deep copy --"
if ! make -C "${BASE}/ex01" re >/dev/null; then
  ko "build ex01"
else
  ok "build ex01"
  out="$("${BASE}/ex01/ex01" 2>&1)"
  dog_ctors="$(echo "${out}" | grep -c 'Dog Default Constructor called.' || true)"
  cat_ctors="$(echo "${out}" | grep -c 'Cat Default Constructor called.' || true)"
  expect_eq "${dog_ctors}" "8" "Dogs: 5 array + dogA + dogC + dogD"
  expect_eq "${cat_ctors}" "5" "array: 5 Cats (impares)"
  expect_contains "${out}" "Dog Copy Constructor called." "copy ctor Dog"
  expect_contains "${out}" "Idea 0 AHola mundo!" "idea en dogA"
  expect_contains "${out}" "Idea 0 BHola mundo!" "idea en dogB (copy)"
  # Tras borrar dogA, dogB sigue con la idea (segunda línea Idea 0 B)
  idea_b="$(echo "${out}" | grep -c 'Idea 0 BHola mundo!' || true)"
  expect_eq "${idea_b}" "2" "deep copy: idea sobrevive a delete dogA"
  brain_dtors="$(echo "${out}" | grep -c 'Brain Destructor called.' || true)"
  if [[ "${brain_dtors}" -ge 10 ]]; then
    ok "Brain dtor (>=10, array + copies)"
  else
    ko "Brain dtor (>=10, array + copies)"
    echo "    got: ${brain_dtors}"
  fi
fi

echo
echo "-- ex02 Abstract Animal --"
if ! make -C "${BASE}/ex02" re >/dev/null; then
  ko "build ex02"
else
  ok "build ex02"
  out="$("${BASE}/ex02/ex02" 2>&1)"
  expect_contains "${out}" "Idea 0 BHola mundo!" "deep copy abstract"
  idea_b="$(echo "${out}" | grep -c 'Idea 0 BHola mundo!' || true)"
  expect_eq "${idea_b}" "2" "deep copy tras delete"
  # Animal abstracta: intentar instanciar debe fallar al compilar
  tmpdir="$(mktemp -d)"
  cat > "${tmpdir}/try_animal.cpp" <<'EOF'
#include "Animal.hpp"
int main() { Animal a; return 0; }
EOF
  if c++ -Wall -Wextra -Werror -std=c++98 -I"${BASE}/ex02" -c "${tmpdir}/try_animal.cpp" -o "${tmpdir}/try_animal.o" 2>/dev/null; then
    ko "Animal no debe instanciarse"
  else
    ok "Animal abstracta (no instancia)"
  fi
  rm -rf "${tmpdir}"
fi

echo
echo "-- ex03 Materia / Character --"
if ! make -C "${BASE}/ex03" re >/dev/null; then
  ko "build ex03"
else
  ok "build ex03"
  out="$("${BASE}/ex03/ex03" 2>&1)"
  expect_contains "${out}" "* shoots an ice bolt at bob *" "Ice::use"
  expect_contains "${out}" "* heals bob's wounds *" "Cure::use"
  expect_contains "${out}" "Returned NULL because it does not exists." "createMateria unknown"
  expect_contains "${out}" "ERROR: Incorrect idx : 67" "use idx inválido"
  expect_contains "${out}" "We are going to unequip 1." "unequip"
  expect_contains "${out}" "ERROR: You are requesting an empty position of the inventory." "use tras unequip"
fi

echo
echo "Resultado: ${pass} OK, ${fail} FAIL"
if [[ "${fail}" -gt 0 ]]; then
  exit 1
fi
exit 0
