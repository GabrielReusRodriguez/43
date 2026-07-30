NAME=rush-00

CFLAGS=-Wall -Wextra -Werror
SRC=rush00.c ft_putchar.c main.c

all: ${NAME}

${NAME}: ${SRC}
	cc ${CFLAGS} -o ${NAME} ${SRC}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re
