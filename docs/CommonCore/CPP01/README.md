# CPP01 (Common Core — C++ Module 01)

Memory allocation, pointers to members, references y `switch`. Siete ejercicios independientes en C++98.

> **Estado:** entrega pedagógica. Estilo C++98 (`-std=c++98`); **no** aplica Norminette (solo módulos C).

## Ubicación

- Código: [`src/CommonCore/CPP01/`](../../../src/CommonCore/CPP01/)
- Subject: [`doc/cpp_01.pdf`](../../../src/CommonCore/CPP01/doc/cpp_01.pdf)
- Tests: [`tests/CommonCore/CPP01/run_tests.sh`](../../../tests/CommonCore/CPP01/run_tests.sh)

## Cómo construir

```bash
make -C src/CommonCore/CPP01/ex00
make -C src/CommonCore/CPP01/ex01
make -C src/CommonCore/CPP01/ex02
make -C src/CommonCore/CPP01/ex03
make -C src/CommonCore/CPP01/ex04
make -C src/CommonCore/CPP01/ex05
make -C src/CommonCore/CPP01/ex06
```

Flags: `-Wall -Wextra -Werror -std=c++98` (+ `-MMD -MP`). Algunos ejercicios añaden `-g3 -fsanitize=address`.

Targets: `all`, `clean`, `fclean`, `re`.

## Ejercicios

### ex00 — BraiiiiiiinnnzzzZ

Clase `Zombie` con `announce()` (`<name>: BraiiiiiiinnnzzzZ...`) y destructor que imprime el nombre.

- `newZombie(name)` → heap (`new` / `delete`)
- `randomChump(name)` → stack (se destruye al salir del scope)

```bash
./zombie
# Zombie heap: BraiiiiiiinnnzzzZ...
# Zombie heap destroyed
# Zombie stack: BraiiiiiiinnnzzzZ...
# Zombie stack destroyed
```

### ex01 — Moar brainz!

`zombieHorde(N, name)` reserva `N` zombies con una sola `new[]`, les pone el mismo nombre y el caller hace `delete[]`.

```bash
./zombie
# 10 announces + 10 destructors
```

### ex02 — HI THIS IS BRAIN

Demuestra que puntero y referencia a un `std::string` comparten la misma dirección y valor.

```bash
./ex02
# Memory Address of string / stringPTR / stringREF (iguales)
# Value ... HI THIS IS BRAIN (tres veces)
```

### ex03 — Unnecessary violence

`Weapon` + `HumanA` (referencia: siempre armado) + `HumanB` (puntero: arma opcional vía `setWeapon`). Cambiar el tipo del arma se refleja en ambos.

```bash
./ex03
# Bob attacks with their crude spiked club
# Bob attacks with their some other type of club
# Jim attacks with their crude spiked club
# Jim attacks with their some other type of club
```

### ex04 — Sed is for losers

`./ex04 <filename> <s1> <s2>` copia el fichero a `<filename>.replace` sustituyendo cada ocurrencia de `s1` por `s2` (sin `std::string::replace`).

```bash
./ex04 file.txt foo bar
# exit 0; escribe file.txt.replace
./ex04 file.txt "" x
# ERROR: s1 must not be empty. (exit 1)
```

### ex05 — Harl 2.0

`Harl::complain(level)` despacha con **punteros a member functions** (sin cascada `if/else`).

```bash
./ex05
# DEBUG / INFO / WARNING / ERROR
```

### ex06 — harlFilter

Filtro por nivel mínimo (`argv[1]`). Imprime ese nivel y los superiores con `switch` + fall-through. Ejecutable: `harlFilter`.

```bash
./harlFilter WARNING
# [ WARNING ] ...
# [ ERROR ] ...
./harlFilter "I am not sure how tired I am today..."
# [ Probably complaining about insignificant problems ]
```

## Estructura

```
src/CommonCore/CPP01/
├── doc/cpp_01.pdf
├── ex00/   Zombie, newZombie, randomChump
├── ex01/   Zombie, zombieHorde
├── ex02/   main (PTR vs REF)
├── ex03/   Weapon, HumanA, HumanB
├── ex04/   Reader/Writter/String handlers (sed)
├── ex05/   Harl (pointers to members)
└── ex06/   harlFilter (switch filter)
```

## Tests

```bash
./tests/CommonCore/CPP01/run_tests.sh
```

Compila cada ejercicio y comprueba announces/destructors, direcciones PTR/REF, ataques HumanA/B, replace + errores de ex04, niveles de Harl y el filtro de ex06.

## Notas

- **ex03:** `HumanA` usa `Weapon&` (siempre armado); `HumanB` usa `Weapon*` (puede no tener arma).
- **ex04:** lectura con `getline` preserva líneas vacías; `s1` vacío se rechaza (evita bucle infinito en `find("")`).
- **ex06:** el `main` solo pasa el nivel de filtro a `complain`; el `switch` hace fall-through desde ese nivel hasta `ERROR`.
- ex06 es opcional según el subject (se puede aprobar el módulo sin él).
