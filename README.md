# 43

Proyectos de mi paso por Badalona 43 (campus 42 Barcelona).

## Índice

| Proyecto | Descripción | Docs | Código |
|----------|-------------|------|--------|
| **Piscina** | Ejercicios de la piscina: Shell00–01, C00–C13, Rush00, BSQ | [docs/Piscina](docs/Piscina/README.md) | [src/Piscina](src/Piscina) |
| **Piscina Reloaded** | Repaso condensado (ex00–ex27) | [docs/PiscinaReloaded](docs/PiscinaReloaded/README.md) | [src/PiscinaReloaded](src/PiscinaReloaded) |
| **Libft** | Librería C del Common Core (`libft.a`) | [docs/CommonCore/libft](docs/CommonCore/libft/README.md) | [src/CommonCore/libft](src/CommonCore/libft) |
| **get_next_line** | Lectura línea a línea desde FD (`libgnl.a`) | [docs/CommonCore/gnl](docs/CommonCore/gnl/README.md) | [src/CommonCore/gnl](src/CommonCore/gnl) |
| **pipex** | Pipeline tipo shell (`infile cmd1 \| cmd2 outfile`) | [docs/CommonCore/pipex](docs/CommonCore/pipex/README.md) | [src/CommonCore/pipex](src/CommonCore/pipex) |
| **ft_printf** | Recreación de `printf` (`libftprintf.a`) | [docs/CommonCore/ft_printf](docs/CommonCore/ft_printf/README.md) | [src/CommonCore/ft_printf](src/CommonCore/ft_printf) |
| **push_swap** | Ordenar un stack con operaciones limitadas | [docs/CommonCore/push_swap](docs/CommonCore/push_swap/README.md) | [src/CommonCore/push_swap](src/CommonCore/push_swap) |
| **philosophers** | Filósofos comensales (threads/mutexes y bonus procesos/semáforos) | [docs/CommonCore/philosophers](docs/CommonCore/philosophers/README.md) | [src/CommonCore/philosophers](src/CommonCore/philosophers) |
| **so_long** | Juego 2D con MiniLibX (mapa `.ber`, coleccionables y salida) | [docs/CommonCore/so_long](docs/CommonCore/so_long/README.md) | [src/CommonCore/so_long](src/CommonCore/so_long) |
| **cub3D** | Raycaster 3D con MLX42 (mapa `.cub`, texturas N/S/E/W) — WIP | [docs/CommonCore/cube3d](docs/CommonCore/cube3d/README.md) | [src/CommonCore/cube3d](src/CommonCore/cube3d) |
| **minishell** | Shell mínima (readline, pipes, redirecciones, builtins) | [docs/CommonCore/minishell](docs/CommonCore/minishell/README.md) | [src/CommonCore/minishell](src/CommonCore/minishell) |

## Norma

- Guía de estilo C (Norminette): [`norma/norma_c.pdf`](norma/norma_c.pdf)

## Tests

```bash
# Piscina (build + smoke)
./tests/Piscina/run_tests.sh
# o
make -C src/Piscina test

# Libft (compilar la librería estática)
make -C src/CommonCore/libft

# get_next_line (compilar libgnl.a; requiere libft)
make -C src/CommonCore/gnl

# pipex (ejecutable; requiere libft + gnl)
make -C src/CommonCore/pipex

# ft_printf (comparar con printf de glibc)
./tests/CommonCore/ft_printf/run_tests.sh

# push_swap (checker_linux; n=3 y n=5)
./tests/CommonCore/push_swap/run_tests.sh

# philosophers (mandatory / bonus)
make -C src/CommonCore/philosophers/src/philo
make -C src/CommonCore/philosophers/src/philo_bonus

# so_long (requiere libft + gnl + MiniLibX; display X11 en Linux)
make -C src/CommonCore/so_long

# cub3D / cube3d (requiere libft + gnl + MLX42/glfw; DISPLAY en Linux)
# Clonar MLX42 una vez: git clone --depth 1 https://github.com/codam-coding-college/MLX42.git src/CommonCore/cube3d/mlx42
./tests/CommonCore/cube3d/run_tests.sh
# o
make -C src/CommonCore/cube3d

# minishell (requiere libft + gnl + libreadline)
make -C src/CommonCore/minishell
```

Piscina Reloaded no tiene runner automatizado; ver [docs/PiscinaReloaded](docs/PiscinaReloaded/README.md) para pruebas manuales.

