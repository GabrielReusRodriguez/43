# BSQ

## Objetivo

**Biggest Square**: dado un mapa rectangular con celdas vacías y obstáculos, encontrar (e imprimir) el cuadrado vacío más grande, marcándolo con el carácter `full` de la cabecera del mapa.

Entrega pedagógica de la piscina, **tal como se dejó** en el momento: carga e impresión de mapas, helpers de parsing/geometría y un esqueleto del algoritmo; la búsqueda del cuadrado máximo aún no está completa.

## Ubicación

- Código: [`src/Piscina/BSQ/`](../../src/Piscina/BSQ/)
- Mapas de ejemplo: [`maps/`](../../src/Piscina/BSQ/maps/)
- Generador: [`scripts/map_generator.pl`](../../src/Piscina/BSQ/scripts/map_generator.pl)

## Formato de mapa

Primera línea: `{n}{empty}{obstacle}{full}` donde `n` es el número de filas (entero) y los tres caracteres siguientes definen vacío, obstáculo y relleno.

Ejemplo (`maps/map_10_20_3.txt`):

```
20.ox
.o....o..o
.......o..
...
```

- `20` filas, vacío `.`, obstáculo `o`, full `x`
- Cada fila siguiente tiene la misma longitud (anchura del mapa)

## Cómo construir y ejecutar

```bash
make -C src/Piscina/BSQ
./src/Piscina/BSQ/bsq src/Piscina/BSQ/maps/map_10_20_3.txt
```

Varios ficheros:

```bash
./src/Piscina/BSQ/bsq map1.txt map2.txt
```

Sin argumentos el programa imprime un mensaje y sale con código 1 (stdin no implementado en esta entrega).

Targets: `all`, `clean`, `fclean`, `re`. Flags: `-Wall -Werror -Wextra`.

### Generar mapas de prueba

```bash
perl src/Piscina/BSQ/scripts/map_generator.pl <ancho> <alto> <densidad>
# ejemplo:
perl src/Piscina/BSQ/scripts/map_generator.pl 10 20 3 > /tmp/map.txt
```

## Estructura

```
src/Piscina/BSQ/
├── Makefile
├── headers/          # includes (.h)
├── src/              # implementación (.c)
├── maps/             # mapas de ejemplo
├── scripts/          # map_generator.pl
└── obj/              # objetos (.o) — no versionado
```

| Archivo | Rol |
|---------|-----|
| `bsq.c` | `main`: carga cada mapa de `argv`, imprime y libera |
| `ft_map.c` / `.h` | `t_map`, carga (`ft_load_map`), impresión, liberado |
| `ft_first_line.c` | Parseo de la cabecera (`n` + caracteres) |
| `ft_line.c` | Lectura de cada fila del mapa |
| `ft_rectangle.c` / `ft_geometry.h` | `t_point`, `t_rectangle`, área |
| `ft_put.c`, `ft_string.c`, `ft_numbers.c`, `ft_buffer.c` | Helpers (I/O, strings, `atoi`, buffer) |

## Notas

- El Makefile declara `INC_FOLDER=./inc`, pero los headers están en `headers/` (los `.c` incluyen `../headers/...`). Tal cual en la entrega.
- `ft_get_next_rectangle` es un stub (devuelve `NULL`); no se marca aún el cuadrado máximo sobre el mapa.
- No está integrado en `make -C src/Piscina` ni en `tests/Piscina/run_tests.sh`.
- Estilo C orientado a la [Norminette](../../norma/norma_c.pdf).
