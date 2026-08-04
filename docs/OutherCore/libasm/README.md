# libasm (Outer Core)

Librería estática en **ensamblador x86-64 (NASM)** del Outer Core de 42: recreación de funciones de la libc (`strlen`, `strcpy`, `strcmp`, `write`, `read`, `strdup`) y bonus de conversión / listas enlazadas.

> **Estado:** entrega pedagógica. Ensamblador NASM `elf64` (Linux); **no** aplica Norminette.

## Ubicación

- Código: [`src/OutherCore/libasm/`](../../../src/OutherCore/libasm/)
- Subject: [`doc/libasm.pdf`](../../../src/OutherCore/libasm/doc/libasm.pdf)
- Tests: [`tests/OutherCore/libasm/run_tests.sh`](../../../tests/OutherCore/libasm/run_tests.sh)
- Material auxiliar: calling convention y notas x86-64 en `doc/`

## Requisitos

- `nasm` (p. ej. `nasm -v`)
- `cc` (gcc/clang) y `ar`/`ld` para tests y el hello de prueba

## Cómo construir

```bash
make -C src/OutherCore/libasm
```

Genera `src/OutherCore/libasm/bin/libasm.a`.

| Target | Efecto |
|--------|--------|
| `all` | Ensambla `src/*.s` → `obj/` y arma `bin/libasm.a` |
| `clean` | Borra `obj/` |
| `fclean` | `clean` + borra `bin/` |
| `re` | `fclean` + `all` |
| `tests` | Compila los binarios de `test/` (depende de `libasm.a`) |
| `hello` | Prueba de concepto: `Hello.s` enlazado con `ld` |

Uso típico al enlazar:

```bash
cc -Wall -Wextra -Werror -I src/OutherCore/libasm/test/inc \
  main.c -L src/OutherCore/libasm/bin -lasm -z execstack
```

`-z execstack` puede ser necesario según toolchain/PIE al mezclar objetos NASM con C.

## Estructura

```
src/OutherCore/libasm/
├── Makefile
├── doc/                 # subject + PDFs de referencia x86-64
├── src/*.s              # implementación NASM
├── obj/                 # objetos (.o) — no versionado
├── bin/libasm.a         # librería estática — no versionada
└── test/
    ├── Makefile
    ├── inc/libft.h      # prototipos usados por los tests
    ├── src/test_*.c
    └── bin/             # ejecutables de prueba
```

## API

Prototipos en [`test/inc/libft.h`](../../../src/OutherCore/libasm/test/inc/libft.h) (el subject no exige un header propio en la entrega).

### Mandatory

| Función | Descripción |
|---------|-------------|
| `size_t ft_strlen(const char *s)` | Longitud hasta `\0` |
| `char *ft_strcpy(char *dst, const char *src)` | Copia incluyendo `\0`; devuelve `dst` |
| `int ft_strcmp(const char *s1, const char *s2)` | Diferencia con signo (como `strcmp`) |
| `ssize_t ft_write(int fd, const void *buf, size_t count)` | Syscall `write` (1); en error pone `errno` y devuelve `-1` |
| `ssize_t ft_read(int fd, void *buf, size_t count)` | Syscall `read` (0); idem |
| `char *ft_strdup(const char *s)` | `malloc` + copia; `NULL` si falla `malloc` |

### Bonus

| Función | Descripción |
|---------|-------------|
| `int ft_atoi_base(const char *str, int str_base)` | String en base `N` (≤ 16) → `int` decimal; acepta espacios iniciales, `-` inicial, dígitos hex mayúsculas/minúsculas |
| `void ft_list_push_front(t_list **lst, t_list *new)` | Inserta `new` al inicio (`new->next = *lst`) |
| `int ft_list_size(t_list *lst)` | Número de nodos |
| `void ft_list_sort(t_list **begin_list, int (*cmp)())` | Bubble sort intercambiando `content` si `cmp > 0` |
| `void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())` | Elimina nodos con `cmp(content, data_ref) == 0` (`free` del nodo; no libera `content`) |

`t_list` es la lista clásica de Libft (`content` + `next`).

## Tests

```bash
./tests/OutherCore/libasm/run_tests.sh
# o
make -C src/OutherCore/libasm tests
# y ejecutar a mano desde test/:
cd src/OutherCore/libasm/test && ./bin/test_strlen
```

Sanitizers opcionales en tests: `make -C src/OutherCore/libasm/test CSANITIZE=1`.

## Notas de implementación

- Convención System V AMD64: args en `rdi`, `rsi`, `rdx`, …; retorno en `rax`.
- `ft_write` / `ft_read` usan `syscall` y `__errno_location` vía GOT (`default rel`).
- `ft_strdup` llama a `ft_strlen` / `ft_strcpy` de la misma librería y a `malloc` de libc.
- El subject de bonus de `ft_list_remove_if` en algunas versiones incluye un 4º argumento `free_fct`; esta entrega usa la firma de 3 argumentos del header del proyecto.

## Correcciones aplicadas en la revisión

- `ft_read`: typo `__erno_location` → `__errno_location`; `NEG` del código de error antes de escribir `errno`.
- `ft_strdup`: comprobación de `malloc` con `JZ` (NULL), llamadas directas a `ft_strlen`/`ft_strcpy`.
- `ft_list_push_front`: siempre asigna `new->next = *lst`.
- `ft_atoi_base`: caracteres entre `'9'` y `'A'` tratados como inválidos.
- Makefiles: `re` reconstruye; typo `text_strcmp.c`; path de `test_read` portable.
