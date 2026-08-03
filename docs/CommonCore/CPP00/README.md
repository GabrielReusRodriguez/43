# CPP00 (Common Core — C++ Module 00)

Primer módulo de C++98: namespaces, clases, member functions, `std::string`, iostreams y static members. Tres ejercicios independientes.

> **Estado:** entrega pedagógica. Estilo C++98 (`-std=c++98`); **no** aplica Norminette (solo módulos C).

## Ubicación

- Código: [`src/CommonCore/CPP00/`](../../../src/CommonCore/CPP00/)
- Subject: [`doc/CPP00_subject.pdf`](../../../src/CommonCore/CPP00/doc/CPP00_subject.pdf)
- Tests: [`tests/CommonCore/CPP00/run_tests.sh`](../../../tests/CommonCore/CPP00/run_tests.sh)

## Cómo construir

Cada ejercicio tiene su propio Makefile:

```bash
make -C src/CommonCore/CPP00/ex00
make -C src/CommonCore/CPP00/ex01
make -C src/CommonCore/CPP00/ex02
```

Flags: `-Wall -Wextra -Werror -std=c++98` (+ `-MMD -MP`).

Targets: `all`, `clean`, `fclean`, `re`.

## Ejercicios

### ex00 — megaphone

Pasa a mayúsculas los argumentos y los imprime concatenados. Sin args: `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.

```bash
./megaphone "shhhhh... I think the students are asleep..."
# SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
# DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
./megaphone
# * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ex01 — My Awesome PhoneBook

Agenda en memoria de hasta **8** contactos (`Contact` + `PhoneBook`). Comandos: `ADD`, `SEARCH`, `EXIT`.

- Campos: first name, last name, nickname, phone number, darkest secret (ninguno vacío).
- Al superar 8 contactos, se sobrescribe el más antiguo (índice circular).
- `SEARCH` muestra tabla de 10 columnas (`setw`) y trunca con `.` si el texto es más largo; luego pide un índice y muestra el contacto completo.

```bash
./phonebook
```

### ex02 — The Job Of Your Dreams

Implementar `Account.cpp` según el header dado (`Account.hpp`) y el log de referencia. `tests.cpp` es del subject.

```bash
./account | cat -e
# Comparar con 19920104_091532.log ignorando el timestamp [YYYYMMDD_HHMMSS]
```

## Estructura

```
src/CommonCore/CPP00/
├── doc/CPP00_subject.pdf
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── Contact.{hpp,cpp}
│   ├── PhoneBook.{hpp,cpp}
│   └── main.cpp
└── ex02/
    ├── Makefile
    ├── Account.{hpp,cpp}      # .hpp del subject; .cpp a implementar
    ├── tests.cpp              # del subject
    └── 19920104_091532.log    # salida de referencia
```

## Tests

```bash
./tests/CommonCore/CPP00/run_tests.sh
```

Comprueba los ejemplos del subject en ex00, un smoke de ADD/SEARCH/campos vacíos/truncado en ex01, y que la salida de ex02 coincida con el log (sin timestamp).

## Notas

- Adaptaciones menores de Makefile (`rm -f`, targets `clean`/`fclean`/`re` en ex01, include de deps en ex02) para poder limpiar/reconstruir en este repo.
- En Account: timestamp con padding `setw(2)`/`setfill('0')` y etiqueta `nb_withdrawals` alineada al log de referencia.
- En PhoneBook: el listado de `SEARCH` se limita a 8 entradas (evita leer fuera del array cuando `total > 8`) y se consume el resto de línea tras leer el índice.
