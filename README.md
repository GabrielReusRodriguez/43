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
```

Piscina Reloaded no tiene runner automatizado; ver [docs/PiscinaReloaded](docs/PiscinaReloaded/README.md) para pruebas manuales.

