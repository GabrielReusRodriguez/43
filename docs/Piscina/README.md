# Piscina (42 Barcelona)

Recopilatorio de ejercicios de la **Piscina** de 42 Barcelona: Shell, C y Rush.

## Ubicación

- Código: [`src/Piscina/`](../../src/Piscina/)
- Subjects PDF: `src/Piscina/<Módulo>/<Módulo>_subject.pdf`
- Tests automatizados: [`tests/Piscina/run_tests.sh`](../../tests/Piscina/run_tests.sh)

## Cómo construir y probar

Desde la raíz del repositorio:

```bash
# Construir todos los módulos C + Rush00
make -C src/Piscina all

# Build + smoke-test de cada ejercicio con Makefile
./tests/Piscina/run_tests.sh
# o bien:
make -C src/Piscina test
```

Por ejercicio:

```bash
make -C src/Piscina/C00/ex00
./src/Piscina/C00/ex00/test_ex00.out
```

Los tests originales son **smoke tests** (`src/test.c`): compilan junto a la solución y escriben por stdout. No hay framework de asserts; el runner comprueba que compilan y que el binario termina con código 0.

## Estructura típica de un ejercicio C

```
C0X/exYY/
├── ft_xxx.c          # solución (entregable)
├── Makefile          # genera test_exYY.out
├── src/test.c        # harness manual
└── bin/              # objetos (gitignored)
```

Targets habituales: `all`, `clean`, `fclean`, `re`.

## Módulos

| Módulo | Ejercicios | Tema |
|--------|------------|------|
| [Shell00](Shell00.md) | ex00–ex09 | Unix básico, permisos, git, scripts |
| [Shell01](Shell01.md) | ex01–ex07 | Scripts shell más avanzados |
| [C00](C00.md) | ex00–ex08 | `write`, bucles, combinaciones |
| [C01](C01.md) | ex00–ex08 | Punteros, arrays |
| [C02](C02.md) | ex00–ex12 | Strings (validación, case, memory dump) |
| [C03](C03.md) | ex00–ex05 | `strcmp`, `strcat`, `strstr`, `strlcat` |
| [C04](C04.md) | ex00–ex05 | `atoi`, bases |
| [C05](C05.md) | ex00–ex08 | Recursividad, primos, 10 reinas |
| [C06](C06.md) | ex00–ex03 | `argc`/`argv` |
| [C07](C07.md) | ex00–ex05 | `malloc`, `split`, bases |
| [C08](C08.md) | ex00–ex05 | Headers, macros, structs |
| [C09](C09.md) | ex00–ex02 | Librería estática, Makefile, `split` |
| [C10](C10.md) | ex00–ex02 | `display_file`, `cat`, `tail` |
| [C11](C11.md) | ex00–ex07 | Punteros a función, `do-op` |
| [C12](C12.md) | ex00–ex17 | Listas enlazadas |
| [C13](C13.md) | ex00–ex07 | Árboles binarios |
| [Rush00](Rush00.md) | ex00 | Rectángulo con patrón de bordes |

**Nota:** Rush01 no está incluido en este repositorio.

Para el repaso condensado posterior a la piscina, ver [Piscina Reloaded](../PiscinaReloaded/README.md).

## Convenciones

- Código C orientado a la [Norminette](../../norma/norma_c.pdf) (`-Wall -Wextra -Werror`).
- Los binarios y `bin/` no se versionan (ver `.gitignore`).
- Los PDF de enunciado sí se versionan como referencia pedagógica.

## Estado conocido

Tras la integración:

- **Build:** 107/107 ejercicios con Makefile OK.
- **Smoke run:** 106/106 binarios ejecutables OK (1 skip: `C09/ex01` es solo `libft.a`).
- **C09/ex01**: estructura `srcs/` + `includes/` completada a partir de ex00.
- **C13/ex02–ex07**: implementaciones y smoke tests añadidos (estaban vacíos).
- **Rush00**: `rush` completado como variante tipo rush03 (`A`/`B`/`C`).
- **C11/ex00–ex04**: algunos `src/test.c` son stubs (`return 0`) y no ejercitan la función; el build pasa.
- **C05/ex00**: el test está comentado/vacío; el build pasa.
- Shell: se valida presencia de scripts; algunos dependen del entorno (`/etc/passwd`, `ifconfig`/`ip`, git).
- **Rush01** no está en el repositorio.
