# Shell00

## Objetivo

Introducción a la shell Unix: ficheros, permisos, tar, git y scripts básicos en `sh`.

## Ejercicios

| Ejercicio | Función/script | Descripción corta |
|-----------|----------------|-------------------|
| ex00 | `z` | Fichero con el carácter `Z` y un salto de línea |
| ex01 | `testShell00.tar` | Archivo tar con ficheros de permisos concretos |
| ex02 | `exo2.tar` | Tar más elaborado (permisos, fechas, tipos) |
| ex03 | `id_rsa_pub` | Clave pública SSH RSA |
| ex04 | `midLS` | Lista el contenido de un directorio (`ls -tpm`) |
| ex05 | `git_commit.sh` | Imprime los 5 últimos hashes de commit |
| ex06 | `git_ignore.sh` | Lista ficheros ignorados por git |
| ex07 | `b` | Fichero de texto (según subject: atributos/enlace) |
| ex08 | `clean` | Borra ficheros `*~` y `#*#` bajo el directorio actual |
| ex09 | `ft_magic` | Regla `magic` para `file(1)` (detecta "42 file") |

## Cómo probar

```bash
# Scripts
sh src/Piscina/Shell00/ex04/midLS .
sh src/Piscina/Shell00/ex05/git_commit.sh
sh src/Piscina/Shell00/ex06/git_ignore.sh
sh src/Piscina/Shell00/ex08/clean

# Tar / magic
tar -tf src/Piscina/Shell00/ex01/testShell00.tar
file -m src/Piscina/Shell00/ex09/ft_magic <algún_fichero>
```

El runner del repo comprueba sobre todo la presencia de scripts.

## Notas

Varios ejercicios dependen del entorno (repo git, `file`, permisos del tar).
