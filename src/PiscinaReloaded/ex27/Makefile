NAME=ft_display_file
CFLAGS=-Wall -Wextra -Werror
SRC_FOLDER=.
INC_FOLDER=.

SRC_FILES=$(wildcard ${SRC_FOLDER}/*.c)
OBJ_FILES=$(SRC_FILES:${SRC_FOLDER}/%.c=%.o)

all:${NAME}

${NAME}:${OBJ_FILES}

%.o:${SRC_FOLDER}/%.c
	cc ${CFLAGS} -I ${INC_FOLDER} -o $@ -c $^

clean:
	rm -f ./*.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
