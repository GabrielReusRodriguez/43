# CPP02 (Common Core — C++ Module 02)

Ad-hoc polymorphism, operator overloading y **Orthodox Canonical Form**. Cuatro ejercicios sobre números en punto fijo (`Fixed`) y BSP.

> **Estado:** entrega pedagógica. Estilo C++98 (`-std=c++98`); **no** aplica Norminette (solo módulos C).

## Ubicación

- Código: [`src/CommonCore/CPP02/`](../../../src/CommonCore/CPP02/)
- Subject: [`doc/cpp_02.pdf`](../../../src/CommonCore/CPP02/doc/cpp_02.pdf)
- Tests: [`tests/CommonCore/CPP02/run_tests.sh`](../../../tests/CommonCore/CPP02/run_tests.sh)

## Cómo construir

```bash
make -C src/CommonCore/CPP02/ex00
make -C src/CommonCore/CPP02/ex01
make -C src/CommonCore/CPP02/ex02
make -C src/CommonCore/CPP02/ex03
```

Flags: `-Wall -Wextra -Werror -std=c++98` (+ `-MMD -MP`).

Targets: `all`, `clean`, `fclean`, `re`.

## Ejercicios

### ex00 — My First Class in Orthodox Canonical Form

Clase `Fixed`: valor raw (`int`) + bits fraccionarios estáticos (`8`). OCF completo + `getRawBits` / `setRawBits`.

```bash
./ex00
# Default / Copy constructor, Copy assignment, getRawBits → 0 × 3, Destructor × 3
```

### ex01 — Towards a more useful fixed-point number class

Constructores `Fixed(int)` y `Fixed(float)` (con `roundf`), `toInt` / `toFloat` y `operator<<`.

```bash
./ex01
# a is 1234.43 / b is 10 / c is 42.4219 / d is 10
# … as integer: 1234, 10, 42, 10
```

### ex02 — Now we’re talking

Comparación, aritmética, `++`/`--` (pre/post, ε = 1/256) y `Fixed::min` / `Fixed::max` (const y no-const).

```bash
./ex02
# 0
# 0.00390625
# 0.00390625
# 0.00390625
# 0.0078125
# 10.1016
# 10.1016
```

### ex03 — BSP

Clase `Point` (`Fixed const x, y`) y `bsp(a, b, c, point)`: `true` solo si el punto está **estrictamente** dentro del triángulo (vértice/arista → `false`).

```bash
./ex03
# outside: 0
# inside:  1
# vertex:  0
# edge:    0
```

## Estructura

```
src/CommonCore/CPP02/
├── doc/cpp_02.pdf
├── ex00/   Fixed (OCF + raw bits)
├── ex01/   Fixed (+ int/float, toInt/toFloat, <<)
├── ex02/   Fixed (+ operators, min/max)
└── ex03/   Fixed + Point + bsp
```

## Tests

```bash
./tests/CommonCore/CPP02/run_tests.sh
```

Comprueba los outputs del subject en ex00–ex02 y casos outside/inside/vertex/edge en ex03.

## Notas

- Desde el Module 02 las clases van en **Orthodox Canonical Form** (salvo excepción explícita).
- Conversión float→fixed con `roundf` (función permitida por el subject).
- `Point` tiene miembros `const`: el `operator=` mantiene la firma OCF sin `const_cast` (no reasigna).
- `bsp` usa productos cruzados (mismo lado); si algún signo es 0 → borde/vértice → `false`.
- ex03 es opcional según el subject.
