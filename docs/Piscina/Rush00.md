# Rush00

## Objetivo

Dibujar un rectángulo de tamaño `x` × `y` con el patrón de bordes `A` / `B` / `C` (variante tipo rush03).

## Ejercicios

| Ejercicio | Función/script | Descripción corta |
|-----------|----------------|-------------------|
| ex00 | `rush` (`rush00.c`) | Imprime el rectángulo; esquinas `A`/`C`, bordes `B` |

## Cómo probar

```bash
make -C src/Piscina/Rush00/ex00
./src/Piscina/Rush00/ex00/rush-00
```

`main.c` llama a `rush(30, 4)` por defecto.

## Notas

Patrón de esta implementación:

- Primera y última fila: `A`, luego `B…`, última columna `C` (si `x > 1`)
- Filas intermedias: `B`, espacios, `B`
- Si `x` o `y` ≤ 0, no imprime nada
