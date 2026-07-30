NAME=libft.a
CFLAGS=-Wall -Wextra -Werror
SRC_FOLDER=./srcs
INC_FOLDER=./includes

SRC_FILES=$(wildcard ${SRC_FOLDER}/*.c)
OBJ_FILES=$(SRC_FILES:${SRC_FOLDER}/%.c=%.o)

all:${NAME}

${NAME}:${OBJ_FILES}
	ar -crs ${NAME} $^

%.o:${SRC_FOLDER}/%.c
	cc ${CFLAGS} -I ${INC_FOLDER} -o $@ -c $^

clean:
	rm -f ./*.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
