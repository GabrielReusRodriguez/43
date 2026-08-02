# minishell (Common Core)

Shell interactiva mínima inspirada en bash: prompt con `readline`, tokenización, expansión de variables, jobs con pipes/redirecciones y ejecución de builtins o binarios externos. Depende de [libft](../libft/README.md), [get_next_line](../gnl/README.md) y `libreadline`.

> **Estado:** entrega pedagógica en progreso / tal cual se está desarrollando en el campus. Compila y enlaza; no todos los builtins del subject están implementados aún.

## Ubicación

- Código: [`src/CommonCore/minishell/`](../../../src/CommonCore/minishell/)
- Subject: [`doc/minishell.pdf`](../../../src/CommonCore/minishell/doc/minishell.pdf)

## Dependencias

- [`libft`](../../../src/CommonCore/libft/) (el Makefile la compila)
- [`gnl`](../../../src/CommonCore/gnl/) (el Makefile la compila)
- `libreadline` (sistema: `-lreadline`)

## Uso

```bash
# Modo interactivo (prompt minishell>)
./bin/minishell

# Ejecutar un comando y salir (modo standalone)
./bin/minishell -c 'echo hello'
```

El código de salida es el de `shell.last_status` (último comando ejecutado).

## Cómo construir

Desde la raíz del repositorio:

```bash
make -C src/CommonCore/minishell
```

Requiere [`src/CommonCore/libft/`](../../../src/CommonCore/libft/) y [`src/CommonCore/gnl/`](../../../src/CommonCore/gnl/) (el Makefile las construye automáticamente).

Genera `src/CommonCore/minishell/bin/minishell`.

Targets:

| Target | Efecto |
|--------|--------|
| `all` | Compila dependencias, objetos en `obj/` y enlaza `bin/minishell` |
| `clean` | Borra `obj/` y hace `clean` en libft/gnl |
| `fclean` | `clean` + borra `bin/` y hace `fclean` en libft/gnl |
| `re` | `fclean` + `all` |

Opcional: `make CSANITIZE=1` añade AddressSanitizer/LeakSanitizer (`-g3 -fsanitize=address -fsanitize=leak`).

Flags de compilación: `-Wall -Werror -Wextra` (+ dependencias `-MMD -MP`).

## Estructura

```
src/CommonCore/minishell/
├── Makefile
├── doc/minishell.pdf     # enunciado
├── include/              # headers por módulo
│   ├── env/              # environment, var_cache
│   ├── tokenizer/        # token, tokenizer
│   └── utils/            # pair, string helpers
├── src/
│   ├── main.c            # entrypoint / modos INTERACTIVE y STANDALONE
│   ├── shell/            # init, loop (readline → execute)
│   ├── tokenizer/        # léxico → lista de tokens
│   ├── expansor/         # expansión de variables / unquote
│   ├── job/              # parseo de tokens → job (lista de cmds)
│   ├── cmd/              # comando, args, redirecciones, FDs
│   ├── executor/         # pipelines, execve, lógica de jobs
│   ├── builtins/         # echo, env, export, exit (+ stubs)
│   ├── env/              # entorno y caché de variables
│   ├── path/             # resolución de binarios y permisos
│   ├── redirect/         # redirecciones
│   ├── file/             # FDs y pipes
│   └── utils/            # strings, pairs
├── obj/                  # objetos (.o) y deps (.d) — no versionado
└── bin/minishell         # ejecutable — no versionado
```

## Módulos

| Módulo | Rol |
|--------|-----|
| `shell` | Inicializa entorno/config; bucle `readline` → tokenize → expand → parse → execute |
| `tokenizer` | Divide la línea en tokens (`WORD`, comillas, `PIPE`, redirecciones, `;`) |
| `expansor` | Expande variables del entorno y limpia comillas |
| `job` / `cmd` | Construye el job (lista de comandos) con args y redirecciones |
| `executor` | Ejecuta el job: pipeline o comando simple; builtins o `execve` |
| `builtins` | `echo`, `env`, `export`, `exit` implementados; `cd`/`pwd`/`unset`/`declare` reconocidos |
| `env` | Copia y gestiona el entorno; exportación a `char **` para `execve` |
| `path` | Localiza el ejecutable y comprueba permisos/tipos |
| `redirect` / `file` | Apertura de FDs de redirección y creación de pipes |

## Flujo

1. `main` inicializa `t_minishell` (entorno + config). Con `-c` entra en modo `STANDALONE`.
2. `minishell_loop` lee la línea (`readline` o comando ya cargado).
3. Tokeniza → expande variables → parsea a un `t_job`.
4. `executor_execute_job` lanza pipelines o comandos simples (builtin / `fork`+`execve`).
5. Libera job/tokens/cmd y actualiza `last_status`; en interactivo vuelve al prompt.

## Builtins

| Builtin | Estado |
|---------|--------|
| `echo` | Implementado |
| `env` | Implementado |
| `export` | Implementado |
| `exit` | Implementado |
| `cd`, `pwd`, `unset`, `declare` | Detectados como builtin; sin handler completo aún |

## Notas

- Enlace con `-lreadline -lft -lgnl`.
- Prompt por defecto: `minishell> ` (con color vía `colours.h`).
- Estilo C orientado a la [Norminette](../../../norma/norma_c.pdf).
- No hay runner en `tests/` para este proyecto; validación habitual con modo `-c` o sesión interactiva.
- `bin/` y `obj/` no se versionan (ver `.gitignore` y `make clean`).
