# cub3D / cube3d (Common Core)

Raycaster en primera persona (estilo Wolfenstein 3D): laberinto 2D con paredes texturizadas N/S/E/W, suelo y techo RGB. Usa **MLX42** (Codam).

> **Estado:** WIP pedagógico. Compila y abre ventana; parsea/valida `.cub` y pinta techo/suelo. **Pendiente:** raycasting (DDA), texturas reales, movimiento WASD y giro con flechas.

## Ubicación

- Código: [`src/CommonCore/cube3d/`](../../../src/CommonCore/cube3d/)
- Mapas: [`maps/`](../../../src/CommonCore/cube3d/maps/)
- Texturas XPM: [`textures/`](../../../src/CommonCore/cube3d/textures/)
- Subject: [`doc/cub3d.pdf`](../../../src/CommonCore/cube3d/doc/cub3d.pdf)
- Tests: [`tests/CommonCore/cube3d/run_tests.sh`](../../../tests/CommonCore/cube3d/run_tests.sh)

## Dependencias

- [`libft`](../libft/README.md) (`../libft`, el Makefile la compila)
- [`gnl`](../gnl/README.md) (`../gnl`, `ft_get_next_line_many_fds`)
- [MLX42](https://github.com/codam-coding-college/MLX42) en `./mlx42` (hay que clonarla una vez)
- Sistema: `cmake`, `libglfw3-dev`, OpenGL/`libgl`, `pthread`, `dl`

```bash
cd src/CommonCore/cube3d
git clone --depth 1 https://github.com/codam-coding-college/MLX42.git mlx42
```

## Uso

Desde el directorio del proyecto (las rutas de texturas en los `.cub` son relativas):

```bash
./cube3d maps/simple.cub
```

| Control (subject) | Estado actual |
|-------------------|---------------|
| **ESC** | Cierra la ventana |
| **W A S D** | No implementado |
| **← →** | No implementado |

## Cómo construir

```bash
make -C src/CommonCore/cube3d
```

Genera `src/CommonCore/cube3d/cube3d` (objetos en `build/`).

| Target | Efecto |
|--------|--------|
| `all` | Compila libft, gnl, MLX42 (cmake) y enlaza `cube3d` |
| `clean` | Borra `build/` (+ clean en libft/gnl) |
| `fclean` | `clean` + borra el binario |
| `re` | `fclean` + `all` |
| `norm` | `norminette` sobre headers y sources |

Opcional: `make CSANITIZE=1` añade AddressSanitizer/LeakSanitizer.

Flags: `-Wall -Werror -Wextra` (+ `-MMD -MP`).

## Formato `.cub`

Cabecera (orden flexible) y **mapa al final**:

| Identificador | Significado |
|---------------|-------------|
| `NO` / `SO` / `WE` / `EA` | Ruta a textura (XPM) |
| `F r,g,b` | Color suelo `[0,255]` |
| `C r,g,b` | Color techo |
| Mapa | `0` vacío, `1` muro, `N/S/E/W` spawn, espacios permitidos |

Mapas de ejemplo: `maps/simple.cub` (compacto), `maps/scene.cub` (ejemplo del subject, líneas irregulares). Casos de error: `maps/bad/`.

## Estructura

```
src/CommonCore/cube3d/
├── Makefile
├── doc/cub3d.pdf
├── include/              # headers por módulo
├── src/
│   ├── main.c
│   ├── config/           # carga .cub, parseo, validación
│   ├── map/ / tile       # representación del mapa
│   ├── flooding/         # flood-fill (mapa cerrado)
│   ├── engine/           # ciclo MLX42 + render
│   ├── events/           # teclado, destroy, resize
│   ├── dda/              # esqueleto raycasting (stub)
│   ├── geometry/         # point, vector, radiants
│   ├── camera.c          # plano de cámara / FOV
│   ├── color.c / screen.c / error.c
├── maps/ / textures/
├── mlx42/                # dependencia externa (no versionada)
├── build/                # objetos
└── ft_utils/             # stub residual (no usado por el Makefile)
```

## Módulos

| Módulo | Rol |
|--------|-----|
| `config/` | Abre el `.cub`, parsea texturas/colores/mapa, valida texturas, colores y jugador |
| `flooding/` | Recorre casillas alcanzables desde el jugador para detectar mapa abierto |
| `engine/` | Inicializa MLX42, hooks, carga de texturas (stub) y bucle de render |
| `events/` | ESC → `engine_stop`; resize de imagen; destroy (vacío) |
| `dda/` | Esqueleto DDA; `check_hit` / bounds aún no implementados |
| `camera` | Construye el plano de cámara según orientación (FOV 0.66); no cableado al engine |
| `geometry/` | Puntos, vectores y rotaciones |
| `map/` / `tile` | Tipos de celda y utilidades (parte legacy junto a `config`) |

## Flujo

1. `argc == 2` o `Error` + exit 1.
2. `config_init` → parse header + mapa → matriz `char **`.
3. `config_validator` → texturas abribles, colores, jugador + flood-fill.
4. `engine_start` → ventana MLX42, imagen full-screen, hooks.
5. Cada frame: pinta mitad superior = techo, inferior = suelo (sin columnas de muro).
6. ESC cierra la ventana; `engine_destroy` libera recursos.

## Tests

```bash
./tests/CommonCore/cube3d/run_tests.sh
```

Comprueba build, errores de argumentos/fichero/validación y smoke GUI (`timeout` 1 s) sobre `simple.cub`. Requiere `DISPLAY` para los casos con ventana.

## Notas / gaps conocidos

- Adaptación del Makefile al layout del repo: `../libft`, `../gnl` y `./mlx42` (antes esperaba copias locales).
- API alineada con la libft del repo (`ft_ptr_free_dchar_ptr`).
- `config_is_header_initialized` comprueba `east_texture` dos veces (no `west`).
- Validación de color usa `> 256` en lugar de `> 255`.
- `width` del mapa se toma de la **última** línea → mapas irregulares mal dimensionados.
- Flood usa indexación `map[x][y]` y bounds mezclados; `scene.cub` se marca abierto.
- Si el flood detecta mapa abierto imprime `Error` pero **sigue** (devuelve `true`) y abre la ventana.
- Texturas: `engine_texture_load` es no-op; DDA no detecta hits; sin movimiento.
- Hay `printf` de depuración en flood/config (no aptos para entrega limpia).
- Estilo C orientado a la [Norminette](../../../norma/norma_c.pdf).
