# Objetivo

Este proyecto es un recopilatorio de proyectos realizados en Barcelona 42 con  fines pedagógicos.

# Stack tecnológico

- Los proyectos están hechos en:
    - bash
    - C
    - C++
    - Docker
    - Python

# Convenciones de código

## Estilo

- Sólo el código C ha de cumplir la norminette de [Norminette](./norma/norma_c.pdf).

# Estructura de carpetas

- `norma/` — carpeta con los documentos que indican los estilos de codificación. 
- `src/` — carpeta con los ejercicios implementados
- `docs/` — documentación de cada ejemplo
- `tests/` — tests automatizados

# Flujo de trabajo

Para implementar una nueva feature:

1. Actualiza el repositorio
2. Crear rama `feature/nombre-descripcion`
3. Implementar el código
4. Hacer commit atómico
5. Crear Pull Request
6. Esperar code review

Para corregir un error:

1. Actualiza el repositorio
2. Crear rama `fix/nombre-descripcion`
3. Implementar el código
4. Hacer commit atómico
5. Crear Pull Request
6. Esperar code review

Antes de hacer commit es obligatorio:

- [ ] Ejecutar linters / revisión de estilo
- [ ] Pasar los tests
- [ ] Actualizar la documentación en `docs/` y, si aplica, el índice de `README.md`
