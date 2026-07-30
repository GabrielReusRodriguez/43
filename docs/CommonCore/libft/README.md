# Libft (Common Core)

Librería estática en C del Common Core de 42: recreación de funciones de la libc, utilidades de strings/memoria, escritura a file descriptor y listas enlazadas (bonus), más helpers propios usados en proyectos posteriores.

## Ubicación

- Código: [`src/CommonCore/libft/`](../../../src/CommonCore/libft/)
- Header: [`include/libft.h`](../../../src/CommonCore/libft/include/libft.h)
- Subject: [`doc/Libft.pdf`](../../../src/CommonCore/libft/doc/Libft.pdf)

## Cómo construir

Desde la raíz del repositorio:

```bash
make -C src/CommonCore/libft
```

Genera `src/CommonCore/libft/bin/libft.a`.

Targets:

| Target | Efecto |
|--------|--------|
| `all` | Compila objetos en `build/` y arma `bin/libft.a` |
| `clean` | Borra `build/` |
| `fclean` | `clean` + borra `bin/` |
| `re` | `fclean` + `all` |

Opcional: `make CSANITIZE=1` añade AddressSanitizer/LeakSanitizer (`-g3 -fsanitize=address -fsanitize=leak`).

Flags de compilación: `-Wall -Werror -Wextra` (+ dependencias `-MMD -MP`).

Uso típico al enlazar desde otro proyecto:

```bash
cc -Wall -Wextra -Werror -I src/CommonCore/libft/include \
  main.c -L src/CommonCore/libft/bin -lft
```

## Estructura

```
src/CommonCore/libft/
├── Makefile
├── doc/Libft.pdf      # enunciado
├── include/libft.h    # API pública
├── src/*.c            # implementación
├── build/             # objetos (.o) y deps (.d) — no versionado
└── bin/libft.a        # librería estática — no versionada
```

## API (por grupos)

Declaraciones en `libft.h`. La librería incluye el set clásico de Libft, el bonus de listas y extensiones propias.

### Errores

| Función | Descripción |
|---------|-------------|
| `ft_err_error` | Mensaje `Error: …` a `stderr` |
| `ft_err_warning` | Mensaje `Warning: …` a `stdout` |
| `ft_err_errno` | `perror` con prefijo opcional |

### Punteros / buffers

| Función | Descripción |
|---------|-------------|
| `ft_ptr_free` | `free` seguro; devuelve `NULL` |
| `ft_ptr_new_char_buffer` | Buffer de `char` cero-terminado (`calloc`) |
| `ft_ptr_free_dchar_ptr` | Libera un `char **` NULL-terminated |

### Memoria

`ft_bzero`, `ft_calloc`, `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`

### Clasificación de caracteres

`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_islower`, `ft_isupper`

### Conversiones

| Función | Descripción |
|---------|-------------|
| `ft_atoi` / `ft_atol` | String → `int` / `long` |
| `ft_itoa` / `ft_utoa` | `int` / `unsigned` → string (`malloc`) |
| `ft_dtoh` / `ft_htoa` | Entero sin signo → hex (`malloc`) |

### Escritura a FD

| Variante | Descripción |
|----------|-------------|
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Escriben sin devolver conteo |
| `ft_iputchar_fd`, `ft_iputstr_fd`, `ft_iputendl_fd`, `ft_iputnbr_fd` | Igual, pero devuelven el número de bytes escritos (`int`) |

### Strings

`ft_strlen`, `ft_strdup`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strcmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`, `ft_toupper`, `ft_tolower`, `ft_istrchr`

### Listas enlazadas (`t_list`) — bonus + extras

| Función | Descripción |
|---------|-------------|
| `ft_lstnew` | Nodo nuevo |
| `ft_lstadd_front` / `ft_lstadd_back` | Insertar al inicio / final |
| `ft_lstsize` / `ft_lstlast` | Tamaño / último nodo |
| `ft_lstdelone` / `ft_lstclear` | Borrar uno / toda la lista |
| `ft_lstiter` / `ft_lstmap` | Iterar / mapear |
| `ft_lstdel_front` / `ft_lstdel_back` | Quitar primer / último nodo (extras) |
| `ft_lstcontains` | Búsqueda con comparador (extra) |

## Notas

- Entrega pedagógica **tal como se usó** en el Common Core: incluye funciones fuera del subject mínimo (errores, hex, `atol`, `iput*`, helpers de lista, etc.).
- Estilo C orientado a la [Norminette](../../../norma/norma_c.pdf).
- No hay runner en `tests/` para esta librería; la validación habitual es compilar `libft.a` y usarla desde otros proyectos del Common Core.
- `bin/` y `build/` no se versionan (ver `.gitignore`).
