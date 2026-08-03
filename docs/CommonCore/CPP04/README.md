# CPP04 (Common Core — C++ Module 04)

Subtype polymorphism, destructores virtuales, clases abstractas e interfaces en C++98.

> **Estado:** entrega pedagógica. Estilo C++98 (`-std=c++98`); **no** aplica Norminette (solo módulos C).

## Ubicación

- Código: [`src/CommonCore/CPP04/`](../../../src/CommonCore/CPP04/)
- Subject: [`doc/cpp_04.pdf`](../../../src/CommonCore/CPP04/doc/cpp_04.pdf)
- Tests: [`tests/CommonCore/CPP04/run_tests.sh`](../../../tests/CommonCore/CPP04/run_tests.sh)

## Cómo construir

```bash
make -C src/CommonCore/CPP04/ex00
make -C src/CommonCore/CPP04/ex01
make -C src/CommonCore/CPP04/ex02
make -C src/CommonCore/CPP04/ex03
```

Flags: `-Wall -Wextra -Werror -std=c++98` (+ `-MMD -MP`).  
ex01–ex03 añaden `-fsanitize=address` (ex01/ex02 con `-g1`, ex03 con `-g3`).

Targets: `all`, `clean`, `fclean`, `re`.

## Ejercicios

### ex00 — Polymorphism

`Animal` → `Dog` / `Cat` con `makeSound()` **virtual**. Contraste con `WrongAnimal` / `WrongCat` (sin `virtual` en `makeSound`): vía puntero a base se llama el de la base.

```bash
./ex00
# dog / cat
# Meu! Meu! / BUP! BUP!
# MakeSound of a generic Wronganimal.   ← WrongCat vía WrongAnimal*
```

### ex01 — I don’t want to set the world on fire

`Dog` / `Cat` poseen un `Brain*` (100 ideas). Copy ctor y `operator=` hacen **deep copy** del `Brain`. Array de `Animal*` mitad Dog / mitad Cat; `delete` vía puntero a base (dtor virtual).

```bash
./ex01
# Idea 0 BHola mundo!  (tras borrar dogA, la copia sigue viva)
```

### ex02 — Abstract class

Igual que ex01, pero `Animal::makeSound() = 0` → clase abstracta (no se puede instanciar `Animal`).

```bash
./ex02
# mismo flujo de deep copy; Animal animal; no compila
```

### ex03 — Interface & recap

Interfaces `ICharacter` / `IMateriaSource` + `AMateria` (abstracta) → `Ice` / `Cure`.  
`Character` (inventario 4) y `MateriaSource` (templates + `createMateria` con `clone()`).

| Pieza | Rol |
|-------|-----|
| `learnMateria` | guarda la materia (ownership) |
| `createMateria` | `clone()` de un template o `NULL` |
| `equip` | toma ownership del puntero |
| `unequip` | **no** hace `delete`; deja la materia en un “suelo” interno |
| `use` | delega en `AMateria::use` |

```bash
./ex03
# * shoots an ice bolt at bob *
# * heals bob's wounds *
```

## Estructura

```
src/CommonCore/CPP04/
├── doc/cpp_04.pdf
├── ex00/   Animal + Dog/Cat + WrongAnimal/WrongCat
├── ex01/   Animal + Dog/Cat + Brain (deep copy)
├── ex02/   Animal abstracta + Dog/Cat + Brain
└── ex03/   AMateria, Ice, Cure, Character, MateriaSource
```

## Tests

```bash
./tests/CommonCore/CPP04/run_tests.sh
```

## Notas

- Destructor **virtual** en `Animal` / `WrongAnimal` / `AMateria` para `delete` vía base.
- OCF en las clases con heap (`Brain`, inventario, templates).
- `operator=` suele devolver `void` en este módulo (válido; el subject no exige `T&`).
- Herencia `virtual public` en Dog/Cat es innecesaria aquí (no hay diamante).
- ex03: copy/assign de `Character` y `MateriaSource` clonan materias (deep copy).
