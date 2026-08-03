# get_next_line (Common Core)

Función que lee un file descriptor línea a línea (`\n` / `\r`), manteniendo un buffer estático entre llamadas. Incluye variante bonus para varios FDs simultáneos. Compila como librería estática `libgnl.a` y depende de [libft](../libft/README.md) (`libft.a` + headers).

## Ubicación

- Código: [`src/CommonCore/gnl/`](../../../src/CommonCore/gnl/)
- Header: [`include/ft_get_next_line.h`](../../../src/CommonCore/gnl/include/ft_get_next_line.h)
- Subject: [`doc/get_next_line.pdf`](../../../src/CommonCore/gnl/doc/get_next_line.pdf)

## Cómo construir

Desde la raíz del repositorio:

```bash
make -C src/CommonCore/gnl
```

Requiere [`src/CommonCore/libft/`](../../../src/CommonCore/libft/) (el Makefile la construye automáticamente y compila con `-I ../libft/include`).

Genera `src/CommonCore/gnl/bin/libgnl.a` (solo símbolos de gnl; los helpers viven en `libft.a`).

Targets:

| Target | Efecto |
|--------|--------|
| `all` | Construye libft, compila objetos en `build/` y arma `bin/libgnl.a` |
| `clean` | Borra `build/` y hace `clean` en libft |
| `fclean` | `clean` + borra `bin/` y hace `fclean` en libft |
| `re` | `fclean` + `all` |

Opcional: `make CSANITIZE=1` añade AddressSanitizer/LeakSanitizer (`-g3 -fsanitize=address -fsanitize=leak`).

Flags de compilación: `-Wall -Werror -Wextra` (+ dependencias `-MMD -MP`). Por defecto el Makefile define `BUFFER_SIZE=30` (`-D BUFFER_SIZE=30`); si no se define en compile-time, el header usa `42`.

Uso típico al enlazar desde otro proyecto:

```bash
cc -Wall -Wextra -Werror \
  -I src/CommonCore/gnl/include -I src/CommonCore/libft/include \
  main.c \
  -L src/CommonCore/gnl/bin -L src/CommonCore/libft/bin \
  -lgnl -lft
```

## Estructura

```
src/CommonCore/gnl/
├── Makefile
├── doc/get_next_line.pdf   # enunciado
├── include/
│   └── ft_get_next_line.h  # API / BUFFER_SIZE / OPEN_MAX
├── src/
│   ├── ft_get_next_line.c        # un FD (static buffer)
│   └── ft_get_next_line_bonus.c  # varios FDs (buffers[OPEN_MAX])
├── build/                  # objetos (.o) y deps (.d) — no versionado
└── bin/libgnl.a            # librería estática — no versionada
```

## API

| Función | Archivo | Descripción |
|---------|---------|-------------|
| `ft_get_next_line(int fd)` | `ft_get_next_line.c` | Lee la siguiente línea de un único FD. Buffer estático entre llamadas. |
| `ft_get_next_line_many_fds(int fd)` | `ft_get_next_line_bonus.c` | Igual, pero un buffer por FD (`OPEN_MAX`). |

Comportamiento común:

- Devuelve un `char *` con la línea (incluido el salto de línea si lo había), o `NULL` en EOF / error / `fd` inválido / `BUFFER_SIZE <= 0`.
- El caller debe liberar la cadena devuelta.
- Detecta fin de línea con `\n` o `\r` (`ft_istrchr`).
- Acumula lecturas de `BUFFER_SIZE` bytes hasta completar una línea.

## Notas

- Entrega pedagógica **tal como se usó** en el Common Core: nombres propios (`ft_get_next_line`, `ft_get_next_line_many_fds`) y dependencia de extensiones de libft (`ft_istrchr`, `ft_ptr_free`, etc.).
- Estilo C orientado a la [Norminette](../../../norma/norma_c.pdf).
- No hay runner en `tests/` para este proyecto; la validación habitual es compilar `libgnl.a` y usarla desde otros proyectos del Common Core (pipex, minishell, …) enlazando también `-lft`.
- `bin/` y `build/` no se versionan (ver `.gitignore` y `make clean`).
