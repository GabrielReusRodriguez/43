# push_swap (Common Core)

Programa que recibe enteros en el stack **a** y escribe en stdout la secuencia de instrucciones (`sa`, `pb`, `ra`, …) que los ordena de menor a mayor con el menor número de operaciones posible. Usa dos stacks y el set de operaciones del enunciado. Depende de [libft](../libft/README.md).

> **Estado:** implementación pedagógica en curso. El algoritmo solo cubre stacks de **3** y **5** elementos; aún no hay `checker` propio (bonus) ni manejo de errores conforme al subject (`Error\n` en stderr).

## Ubicación

- Código: [`src/CommonCore/push_swap/`](../../../src/CommonCore/push_swap/)
- Subject: [`doc/push_swap.subject.pdf`](../../../src/CommonCore/push_swap/doc/push_swap.subject.pdf)
- Checkers oficiales (recursos): [`checkers/`](../../../src/CommonCore/push_swap/checkers/)
- Tests: [`tests/CommonCore/push_swap/`](../../../tests/CommonCore/push_swap/)

## Uso

```bash
./push_swap 2 1 3 6 5
# imprime instrucciones, una por línea

ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checkers/checker_linux $ARG   # OK / KO
```

El primer argumento es la cima del stack **a**.

## Cómo construir

Desde la raíz del repositorio:

```bash
make -C src/CommonCore/push_swap
```

Requiere [`src/CommonCore/libft/`](../../../src/CommonCore/libft/) (el Makefile la construye automáticamente).

Genera el ejecutable `src/CommonCore/push_swap/push_swap` (objetos en `bin/`).

Targets:

| Target | Efecto |
|--------|--------|
| `all` | Compila libft, objetos en `bin/` y enlaza `push_swap` |
| `clean` | Borra objetos/deps en `bin/` |
| `fclean` | `clean` + borra `push_swap` |
| `re` | `fclean` + `all` |

Flags: `-Wall -Werror -Wextra` (+ `-MMD -MP`). Includes: `src/` y `libft/include`.

## Estructura

```
src/CommonCore/push_swap/
├── Makefile
├── doc/push_swap.subject.pdf
├── checkers/           # checker_linux / checker_Mac (binarios del campus)
├── src/
│   ├── ft_push_swap.c  # main / carga de argumentos
│   ├── ft_stack*.c/h   # lista enlazada (stack)
│   ├── ft_validations.*# enteros / duplicados / orden
│   ├── ft_primitives_* # sa/sb/ss, pa/pb, ra/rb/rr, rra/rrb/rrr
│   ├── ft_actions.c    # ejecuta primitiva + imprime nombre
│   └── ft_sort.*       # algoritmo (3 y 5 elementos)
├── bin/                # .o / .d — no versionado
└── push_swap           # ejecutable — no versionado
```

## Módulos

| Módulo | Rol |
|--------|-----|
| `ft_push_swap` | Parsea `argv`, rellena el stack **a** (push desde el último arg) y llama a `ft_sort` |
| `ft_stack` | Push/pop/size/clear sobre lista enlazada genérica (`void *content`) |
| `ft_validations` | Entero con signo opcional; detección de duplicados; helpers de orden |
| `ft_primitives_*` | Operaciones del lenguaje Push swap sobre los stacks |
| `ft_actions` | Despacha la primitiva e imprime `sa\n`, `pb\n`, etc. |
| `ft_sort` | Caso 3: `sa`/`rra` hasta ordenar. Caso 5: `pb`×2, ordenar 3 en **a**, reinsertar desde **b** |

## Operaciones (subject)

| Op | Efecto |
|----|--------|
| `sa` / `sb` / `ss` | Swap de los dos primeros en a, b, o ambos |
| `pa` / `pb` | Push de b→a o a→b |
| `ra` / `rb` / `rr` | Rotate (cima → fondo) |
| `rra` / `rrb` / `rrr` | Reverse rotate (fondo → cima) |

## Tests

```bash
./tests/CommonCore/push_swap/run_tests.sh
```

El runner compila el proyecto y valida con `checkers/checker_linux` las permutaciones de tamaño 3 y varios casos de tamaño 5. También comprueba que tamaños no soportados (p. ej. 4) no pasan el checker (comportamiento actual documentado).

## Limitaciones conocidas

- Solo ordena **n = 3** y **n = 5** (`ft_sort`); otros tamaños no generan una secuencia correcta.
- `main` exige `argc >= 4` (≥ 3 números); el subject permite 0 args (silencio) y cualquier cantidad válida.
- Mensajes de error de depuración en stdout en lugar de `Error\n` en stderr.
- No hay binario `checker` propio (bonus del enunciado).
- Estilo C orientado a la [Norminette](../../../norma/norma_c.pdf); el código aún contiene restos de depuración.
