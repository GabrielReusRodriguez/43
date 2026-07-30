# Shell01

## Objetivo

Scripts shell más avanzados: usuarios, find, red, variables de entorno y parseo de `/etc/passwd`.

## Ejercicios

| Ejercicio | Función/script | Descripción corta |
|-----------|----------------|-------------------|
| ex01 | `print_groups.sh` | Grupos de `$FT_USER` separados por comas |
| ex02 | `find_sh.sh` | Nombres de ficheros `*.sh` (sin ruta ni extensión) |
| ex03 | `count_files.sh` | Cuenta ficheros y directorios bajo `.` |
| ex04 | `MAC.sh` | Direcciones MAC de las interfaces de red |
| ex05 | `"\?$*'MaRViN'*$?\"` | Fichero con nombre especial (caracteres raros) |
| ex06 | `skip.sh` | `ls -l` saltando una línea de cada dos |
| ex07 | `r_dwssap.sh` | Login invertidos de `/etc/passwd` (líneas pares, rango `$FT_LINE1`–`$FT_LINE2`) |

## Cómo probar

```bash
FT_USER=$(whoami) sh src/Piscina/Shell01/ex01/print_groups.sh
sh src/Piscina/Shell01/ex02/find_sh.sh
sh src/Piscina/Shell01/ex03/count_files.sh
sh src/Piscina/Shell01/ex04/MAC.sh
sh src/Piscina/Shell01/ex06/skip.sh .
FT_LINE1=7 FT_LINE2=15 sh src/Piscina/Shell01/ex07/r_dwssap.sh
```

No hay `ex00` en este módulo.

## Notas

`MAC.sh` usa `ifconfig`. `r_dwssap.sh` lee `/etc/passwd` y usa `FT_LINE1` / `FT_LINE2`.
