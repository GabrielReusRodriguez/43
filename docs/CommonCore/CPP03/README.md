# CPP03 (Common Core — C++ Module 03)

Inheritance en C++98: `ClapTrap`, `ScavTrap`, `FragTrap` y (opcional) `DiamondTrap` con herencia virtual.

> **Estado:** entrega pedagógica. Estilo C++98 (`-std=c++98`); **no** aplica Norminette (solo módulos C).

## Ubicación

- Código: [`src/CommonCore/CPP03/`](../../../src/CommonCore/CPP03/)
- Subject: [`doc/cpp_03.pdf`](../../../src/CommonCore/CPP03/doc/cpp_03.pdf)
- Tests: [`tests/CommonCore/CPP03/run_tests.sh`](../../../tests/CommonCore/CPP03/run_tests.sh)

## Cómo construir

```bash
make -C src/CommonCore/CPP03/ex00
make -C src/CommonCore/CPP03/ex01
make -C src/CommonCore/CPP03/ex02
make -C src/CommonCore/CPP03/ex03
```

Flags: `-Wall -Wextra -Werror -std=c++98` (+ `-MMD -MP`). ex03 añade `-Wshadow`.

Targets: `all`, `clean`, `fclean`, `re`.

## Ejercicios

### ex00 — Aaaaand... OPEN!

`ClapTrap`: HP 10, EP 10, AD 0. Acciones `attack`, `takeDamage`, `beRepaired` (atacar/reparar cuestan 1 EP; sin HP o EP no actúa).

```bash
./ex00
# attack / damage / repair / muerto no actúa
```

### ex01 — Serena, my love!

`ScavTrap` hereda `ClapTrap`: HP 100, EP 50, AD 20. `attack` con mensaje propio + `guardGate()`. Construcción ClapTrap → ScavTrap; destrucción en orden inverso.

```bash
./ex01
# ScavTrap … attacks … causing 20 …
# ScavTrap is now in Gate keeper mode.
```

### ex02 — Repetitive work

`FragTrap` hereda `ClapTrap`: HP 100, EP 100, AD 30. Capacidad `highFivesGuys()`.

```bash
./ex02
# … causing 30 points of damage!
# FragTrap … request highFive!
```

### ex03 — Now it’s weird!

`DiamondTrap` hereda `FragTrap` **y** `ScavTrap` (con `virtual` en ambos hacia `ClapTrap`).

| Atributo / método | Origen |
|-------------------|--------|
| `name` (Diamond) | parámetro del ctor |
| `ClapTrap::_name` | `name + "_clap_name"` |
| Hit points | FragTrap (100) |
| Energy points | ScavTrap (50) |
| Attack damage | FragTrap (30) |
| `attack()` | ScavTrap |
| Extra | `whoAmI()`, `guardGate()`, `highFivesGuys()` |

```bash
./ex03
# DiamondTrap name: Gabriel.
# ClapTrap name: Gabriel_clap_name.
# HP: 100 / EP: 50 / AD: 30
```

## Estructura

```
src/CommonCore/CPP03/
├── doc/cpp_03.pdf
├── ex00/   ClapTrap
├── ex01/   ClapTrap + ScavTrap
├── ex02/   ClapTrap + FragTrap
└── ex03/   ClapTrap + ScavTrap + FragTrap + DiamondTrap
```

## Tests

```bash
./tests/CommonCore/CPP03/run_tests.sh
```

## Notas

- OCF en todas las clases (Module 02+).
- `beRepaired` exige HP > 0 y EP > 0 (no revive un ClapTrap muerto).
- `virtual` inheritance solo en **ex03** (ScavTrap/FragTrap → ClapTrap); en ex01/ex02 la herencia es simple.
- `DiamondTrap` declara su propio `_name` (mismo identificador que en `ClapTrap`); el copy/assign copia ambos nombres.
- ex03 es opcional según el subject.
