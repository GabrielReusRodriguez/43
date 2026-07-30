# pipex (Common Core)

Programa que emula el pipeline de la shell: `infile cmd1 | cmd2 | … | cmdN outfile`. Incluye bonus con `here_doc` (equivalente a `<<`) y varios comandos encadenados. Depende de [libft](../libft/README.md) y [get_next_line](../gnl/README.md) (heredoc).

## Ubicación

- Código: [`src/CommonCore/pipex/`](../../../src/CommonCore/pipex/)
- Subject: [`doc/pipex.pdf`](../../../src/CommonCore/pipex/doc/pipex.pdf)

## Uso

```bash
# Modo normal (mínimo 4 argumentos)
./bin/pipex infile "cmd1" "cmd2" outfile
# equivalente a: < infile cmd1 | cmd2 > outfile

# Varios comandos (bonus)
./bin/pipex infile "cmd1" "cmd2" "cmd3" … outfile

# here_doc (bonus)
./bin/pipex here_doc LIMITER "cmd1" "cmd2" outfile
# equivalente a: cmd1 << LIMITER | cmd2 >> outfile
```

El código de salida es el del último comando hijo.

## Cómo construir

Desde la raíz del repositorio:

```bash
make -C src/CommonCore/pipex
```

Requiere [`src/CommonCore/libft/`](../../../src/CommonCore/libft/) y [`src/CommonCore/gnl/`](../../../src/CommonCore/gnl/) (el Makefile las construye automáticamente).

Genera `src/CommonCore/pipex/bin/pipex`.

Targets:

| Target | Efecto |
|--------|--------|
| `all` | Compila dependencias, objetos en `obj/` y enlaza `bin/pipex` |
| `clean` | Borra `obj/` y hace `clean` en libft/gnl |
| `fclean` | `clean` + borra `bin/` y hace `fclean` en libft/gnl |
| `re` | `fclean` + `all` |

Opcional: `make CSANITIZE=1` añade AddressSanitizer/LeakSanitizer (`-g3 -fsanitize=address -fsanitize=leak`).

Flags de compilación: `-Wall -Werror -Wextra` (+ dependencias `-MMD -MP`).

## Estructura

```
src/CommonCore/pipex/
├── Makefile
├── doc/pipex.pdf       # enunciado
├── include/            # headers por módulo
├── src/
│   ├── pipex.c         # main / orquestación
│   ├── ft_exec.c       # fork + pipe + execve
│   ├── ft_child.c      # redirección stdout en el hijo
│   ├── ft_parent.c     # redirección stdin en el padre + wait
│   ├── ft_files.c      # infile / outfile / here_doc
│   ├── ft_fd.c         # utilidades de FD
│   ├── ft_environment.c# PATH desde envp
│   ├── ft_path.c       # resolución de binarios (which)
│   └── ft_error.c      # mensajes de error / exit
├── obj/                # objetos (.o) y deps (.d) — no versionado
└── bin/pipex           # ejecutable — no versionado
```

## Módulos

| Módulo | Rol |
|--------|-----|
| `pipex.c` | Valida `argc`, abre FDs, construye el entorno y encadena comandos |
| `ft_exec` | Crea `pipe`/`fork`; el hijo ejecuta el comando, el padre reencamina stdin |
| `ft_child` | `dup2` a pipe o a outfile y llama a `execve` |
| `ft_parent` | Cierra write del pipe, `dup2` read→stdin; espera hijos y traduce el status |
| `ft_files` | Abre infile (`O_RDONLY`) u outfile (`O_TRUNC` / `O_APPEND` con heredoc); lee stdin hasta el LIMITER |
| `ft_environment` | Parsea `PATH=` de `envp` (carpetas con `/` final) |
| `ft_path` | Localiza el binario (`access` con ruta absoluta o búsqueda en `PATH`) |
| `ft_fd` | Comprueba FDs, `dup2` inicial stdin/stdout, cierre selectivo de pipes |
| `ft_error` | `perror` / mensaje a stderr y, si aplica, `exit` |

## Flujo

1. Abrir entrada (`infile` o pipe del heredoc) y salida (`outfile`).
2. `dup2` de esos FDs a stdin/stdout del proceso principal.
3. Para cada comando intermedio: `pipe` → `fork` → hijo escribe en el pipe y hace `execve`; padre lee del pipe hacia stdin.
4. El último comando redirige stdout al outfile.
5. Esperar a todos los hijos y devolver el status del último.

## Notas

- Entrega pedagógica **tal como se usó** en el Common Core: bonus de múltiples pipes y `here_doc` incluidos en el mismo binario.
- El heredoc usa `ft_get_next_line_many_fds` de gnl y muestra el prompt `pipe heredoc> `.
- Estilo C orientado a la [Norminette](../../../norma/norma_c.pdf).
- No hay runner en `tests/` para este proyecto; la validación habitual es comparar la salida con el pipeline equivalente de la shell.
- `bin/` y `obj/` no se versionan (ver `.gitignore` y `make clean`).
