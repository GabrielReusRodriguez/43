# so_long (Common Core)

Juego 2D sencillo con MiniLibX: el jugador recoge todos los coleccionables y llega a la salida. Incluye parte **mandatory** y **bonus** (enemigos / contador en pantalla).

> **Estado:** entrega pedagógica tal cual se realizó en el campus, adaptada para compilar también en Linux (MiniLibX X11, keycodes y event masks). Conserva `mlx_GL` para macOS.

## Ubicación

- Código mandatory: [`src/CommonCore/so_long/src/`](../../../src/CommonCore/so_long/src/)
- Código bonus: [`src/CommonCore/so_long/src_bonus/`](../../../src/CommonCore/so_long/src_bonus/)
- Headers: [`inc/`](../../../src/CommonCore/so_long/inc/) / [`inc_bonus/`](../../../src/CommonCore/so_long/inc_bonus/)
- Mapas: [`maps/`](../../../src/CommonCore/so_long/maps/)
- Sprites: [`sprites/`](../../../src/CommonCore/so_long/sprites/)
- Subject: [`doc/so_long.pdf`](../../../src/CommonCore/so_long/doc/so_long.pdf)

## Dependencias

- [`libft`](../../../src/CommonCore/libft/) (el Makefile la compila)
- [`gnl`](../../../src/CommonCore/gnl/) (`ft_get_next_line_many_fds`, se compila como objeto del proyecto)
- MiniLibX: `mlx/` en Linux, `mlx_GL/` en macOS (selección automática por `uname`)
- Linux: `libX11`, `libXext`, `libbsd`, zlib

## Uso

```bash
./so_long maps/6x6.ber
```

Controles: **W A S D** (movimiento) y **ESC** (salir). En macOS los keycodes son los del subject; en Linux los de X11.

## Cómo construir

```bash
make -C src/CommonCore/so_long
make -C src/CommonCore/so_long bonus
```

Genera el ejecutable `so_long` en el directorio del proyecto (objetos en `obj/`).

Targets: `all`, `bonus`, `clean`, `fclean`, `re`, `norminette`. Flags: `-Wall -Wextra -Werror`.

## Estructura

```
src/CommonCore/so_long/
├── Makefile
├── doc/so_long.pdf
├── inc/ / src/           # mandatory
├── inc_bonus/ / src_bonus/
├── maps/
├── sprites/
├── mlx/                  # MiniLibX Linux (X11)
└── mlx_GL/               # MiniLibX macOS (OpenGL)
```

## Notas

- El mapa debe ser rectangular, cerrado por muros, con 1 jugador (`P`), 1 salida (`E`) y al menos 1 coleccionable (`C`).
- Se valida que exista un camino alcanzable (BFS) antes de abrir la ventana.
- Mapas de error de ejemplo: `maps/err_*.ber`.
