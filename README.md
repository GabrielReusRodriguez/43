# 43

Proyectos de mi paso por Badalona 43 (campus 42 Barcelona).

## Índice

| Proyecto | Descripción | Docs | Código |
|----------|-------------|------|--------|
| **Piscina** | Ejercicios de la piscina: Shell00–01, C00–C13, Rush00 | [docs/Piscina](docs/Piscina/README.md) | [src/Piscina](src/Piscina) |
| **Piscina Reloaded** | Repaso condensado (ex00–ex27) | [docs/PiscinaReloaded](docs/PiscinaReloaded/README.md) | [src/PiscinaReloaded](src/PiscinaReloaded) |
| **Libft** | Librería C del Common Core (`libft.a`) | [docs/CommonCore/libft](docs/CommonCore/libft/README.md) | [src/CommonCore/libft](src/CommonCore/libft) |
| **get_next_line** | Lectura línea a línea desde FD (`libgnl.a`) | [docs/CommonCore/gnl](docs/CommonCore/gnl/README.md) | [src/CommonCore/gnl](src/CommonCore/gnl) |

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
```

Piscina Reloaded no tiene runner automatizado; ver [docs/PiscinaReloaded](docs/PiscinaReloaded/README.md) para pruebas manuales.
