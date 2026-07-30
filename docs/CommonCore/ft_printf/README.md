# ft_printf (Common Core)

Librería estática en C del Common Core de 42: recreación de `printf()` con argumentos variables (`va_list`). Genera `libftprintf.a` y reutiliza [libft](../libft/README.md).

## Ubicación

- Código: [`src/CommonCore/ft_printf/`](../../../src/CommonCore/ft_printf/)
- Header: [`include/ft_printf.h`](../../../src/CommonCore/ft_printf/include/ft_printf.h)
- Subject: [`doc/ft_printf.pdf`](../../../src/CommonCore/ft_printf/doc/ft_printf.pdf)
- Tests: [`tests/CommonCore/ft_printf/`](../../../tests/CommonCore/ft_printf/)

## Cómo construir

Desde la raíz del repositorio:

```bash
make -C src/CommonCore/ft_printf
```

Requiere [`src/CommonCore/libft/`](../../../src/CommonCore/libft/) (el Makefile la compila primero).

Genera `src/CommonCore/ft_printf/bin/libftprintf.a`.

Targets:

| Target | Efecto |
|--------|--------|
| `all` | Compila libft, objetos en `build/` y arma `bin/libftprintf.a` |
| `clean` | Borra `build/` (y clean de libft) |
| `fclean` | `clean` + borra `bin/` (y fclean de libft) |
| `re` | `fclean` + `all` |

Opcional: `make CSANITIZE=1` añade AddressSanitizer/LeakSanitizer.

Flags: `-Wall -Werror -Wextra` (+ `-MMD -MP`).

Uso típico al enlazar:

```bash
cc -Wall -Wextra -Werror \
  -I src/CommonCore/ft_printf/include -I src/CommonCore/libft/include \
  main.c \
  -L src/CommonCore/ft_printf/bin -lftprintf \
  -L src/CommonCore/libft/bin -lft
```

Ejemplo rápido:

```bash
make -C src/CommonCore/ft_printf
make -C src/CommonCore/ft_printf/examples
./src/CommonCore/ft_printf/examples/printf.out
```

## Estructura

```
src/CommonCore/ft_printf/
├── Makefile
├── doc/ft_printf.pdf
├── include/ft_printf.h
├── src/                 # parseo de formato + conversiones
├── examples/            # smoke manual
├── build/               # no versionado
└── bin/libftprintf.a    # no versionada
```

## API

| Función | Descripción |
|---------|-------------|
| `ft_printf(char const *fmt, ...)` | Como `printf` hacia stdout; devuelve bytes escritos o `-1` |
| `ft_printf_fd(int fd, char const *fmt, ...)` | Igual, hacia un file descriptor |

Conversiones obligatorias: `cspdiuxX%`.

Flags / ancho / precisión (bonus, integrados en el mismo código): `-0.# +`, width y precision.

## Tests

```bash
./tests/CommonCore/ft_printf/run_tests.sh
# o
make -C tests/CommonCore/ft_printf test
```

El harness compara salida y valor de retorno con el `printf` de glibc (casos obligatorios + bonus representativos).

## Notas

- Estilo C orientado a la [Norminette](../../../norma/norma_c.pdf).
- `bin/` y `build/` no se versionan.
- El enunciado pide archivos `*_bonus` y regla `bonus` para evaluar bonus por separado; esta entrega pedagógica lleva flags bonus en el código principal.
