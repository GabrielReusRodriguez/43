# C Piscine Reloaded

Repaso condensado de la Piscina: shell, funciones C básicas, headers, Makefile y un pequeño programa de ficheros.

## Ubicación

- Código: [`src/PiscinaReloaded/`](../../src/PiscinaReloaded/)
- Subject: [`CPiscine_Reloaded.pdf`](../../src/PiscinaReloaded/CPiscine_Reloaded.pdf)

## Cómo explorar / probar

No hay runner automatizado propio (a diferencia de `src/Piscina`). Cada ejercicio se prueba según su tipo:

```bash
# Scripts shell
sh src/PiscinaReloaded/ex02/clean
sh src/PiscinaReloaded/ex03/find_sh.sh
sh src/PiscinaReloaded/ex04/MAC.sh

# Funciones C (compilar a mano o con un main de prueba)
cc -Wall -Wextra -Werror -c src/PiscinaReloaded/ex06/ft_print_alphabet.c

# Programas con main (ex18, ex19, …)
cc -Wall -Wextra -Werror -o sort_params src/PiscinaReloaded/ex19/ft_sort_params.c
./sort_params c b a

# display_file (ex27)
make -C src/PiscinaReloaded/ex27
```

## Ejercicios

| Ej. | Entregable | Descripción corta |
|-----|------------|-------------------|
| ex00 | `exo.tar` | Archivo tar de entrega (permisos/estructura) |
| ex01 | `z` | Fichero con `Z` y salto de línea |
| ex02 | `clean` | Borra `*~` y `#*#` bajo el directorio actual |
| ex03 | `find_sh.sh` | Lista ficheros `*.sh` (sin extensión en la salida) |
| ex04 | `MAC.sh` | Muestra direcciones MAC de las interfaces |
| ex05 | `"\?$*'MaRViN'*$?\"` | Fichero con nombre especial; contenido `42` |
| ex06 | `ft_print_alphabet` | Imprime `a`–`z` |
| ex07 | `ft_print_numbers` | Imprime `0`–`9` |
| ex08 | `ft_is_negative` | Imprime `N` o `P` según el signo |
| ex09 | `ft_ft` | Asigna `42` a través de un puntero |
| ex10 | `ft_swap` | Intercambia dos `int` |
| ex11 | `ft_div_mod` | División y módulo vía punteros |
| ex12 | `ft_iterative_factorial` | Factorial iterativo |
| ex13 | `ft_recursive_factorial` | Factorial recursivo |
| ex14 | `ft_sqrt` | Raíz cuadrada entera (0 si no es perfecta) |
| ex15 | `ft_putstr` | Escribe una cadena |
| ex16 | `ft_strlen` | Longitud de cadena |
| ex17 | `ft_strcmp` | Comparación de cadenas |
| ex18 | `ft_print_params` | Programa: imprime los argumentos |
| ex19 | `ft_sort_params` | Programa: imprime argumentos ordenados |
| ex20 | `ft_strdup` | Duplica una cadena (`malloc`) |
| ex21 | `ft_range` | Array de `int` de `min` a `max` (excluido) |
| ex22 | `ft_abs.h` | Macro `ABS(Value)` |
| ex23 | `ft_point.h` | Struct `t_point` (`x`, `y`) |
| ex24 | `Makefile` | Build de `libft.a` (`srcs/` + `includes/`) |
| ex25 | `ft_foreach` | Aplica una función a cada entero de un array |
| ex26 | `ft_count_if` | Cuenta strings para los que `f` es verdadero |
| ex27 | `ft_display_file` (+ helpers) | Muestra el contenido de un fichero |

## Notas

- Reloaded reúne piezas de Shell00/01 y C00–C11 en un solo subject; no sustituye a [`docs/Piscina`](../Piscina/README.md).
- **ex24** entrega solo el `Makefile` (espera `srcs/` e `includes/` en el entorno de evaluación).
- Algunos `.c` (p. ej. ex12–ex14, ex18–ex19, ex21) incluyen un `main` de prueba local; en entrega real a menudo no se incluye.
- Estilo C alineado con la [Norminette](../../norma/norma_c.pdf).
