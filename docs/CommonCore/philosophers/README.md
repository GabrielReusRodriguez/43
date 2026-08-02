# Philosophers (Common Core)

Simulación del problema de los filósofos comensales. La parte **mandatory** usa hilos y mutexes (`philo`); el **bonus** usa procesos y semáforos (`philo_bonus`).

> **Estado:** entrega pedagógica tal cual se realizó en el campus. Incluye mandatory y bonus; no se ha refactorizado ni corregido frente a evaluadores posteriores.

## Ubicación

- Código mandatory: [`src/CommonCore/philosophers/src/philo/`](../../../src/CommonCore/philosophers/src/philo/)
- Código bonus: [`src/CommonCore/philosophers/src/philo_bonus/`](../../../src/CommonCore/philosophers/src/philo_bonus/)
- Subject: [`doc/philosophers.pdf`](../../../src/CommonCore/philosophers/doc/philosophers.pdf)

## Uso

```bash
# número_de_filósofos time_to_die time_to_eat time_to_sleep [número_de_comidas]
./philo 5 800 200 200
./philo 5 800 200 200 7
```

Cada filósofo es un hilo (mandatory) o un proceso (bonus). Los logs siguen el formato del subject (`timestamp_ms id action`).

## Cómo construir

```bash
make -C src/CommonCore/philosophers/src/philo
make -C src/CommonCore/philosophers/src/philo_bonus
```

Generan el ejecutable `philo` en cada directorio (objetos en `obj/`). No dependen de libft.

Targets: `all`, `clean`, `fclean`, `re`. Flags: `-Wall -Wextra -Werror` (mandatory enlaza con `-pthread`).

## Estructura

```
src/CommonCore/philosophers/
├── doc/philosophers.pdf
└── src/
    ├── philo/          # threads + mutexes
    │   ├── Makefile
    │   ├── inc/
    │   ├── src/
    │   └── obj/        # no versionado
    └── philo_bonus/    # processes + semaphores
        ├── Makefile
        ├── *.c / *.h
        └── obj/        # no versionado
```

## Notas

- Argumentos: 4 o 5 valores enteros positivos (el 5.º, comidas, es opcional).
- La simulación termina cuando un filósofo muere o cuando todos alcanzan el número de comidas.
- Enlaces del subject: sincronización sin data races; retraso máximo ~10 ms al anunciar `died`.
