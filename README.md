# 43

Proyectos de mi paso por Badalona 43 (campus 42 Barcelona).

## Índice

| Proyecto | Descripción | Docs | Código |
|----------|-------------|------|--------|
| **Piscina** | Ejercicios de la piscina: Shell00–01, C00–C13, Rush00 | [docs/Piscina](docs/Piscina/README.md) | [src/Piscina](src/Piscina) |
| **Piscina Reloaded** | Repaso condensado (ex00–ex27) | [docs/PiscinaReloaded](docs/PiscinaReloaded/README.md) | [src/PiscinaReloaded](src/PiscinaReloaded) |

## Norma

- Guía de estilo C (Norminette): [`norma/norma_c.pdf`](norma/norma_c.pdf)

## Tests

```bash
# Piscina (build + smoke)
./tests/Piscina/run_tests.sh
# o
make -C src/Piscina test
```

Piscina Reloaded no tiene runner automatizado; ver [docs/PiscinaReloaded](docs/PiscinaReloaded/README.md) para pruebas manuales.
