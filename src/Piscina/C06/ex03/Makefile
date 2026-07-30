NAME=test_ex03.out
EXERCISE=ft_sort_params
TEST=test

CFLAGS= -Wall -Wextra -Werror 
SRC_DIR=./src
BIN_DIR=./bin

all: ${NAME}

clean:
	rm -f ${BIN_DIR}/*

fclean: clean
	rm -f ./${NAME}

re: fclean all

${NAME}: ${BIN_DIR}/${EXERCISE}.o
	cc ${CFLAGS} $^ -o ${NAME}

${BIN_DIR}/${EXERCISE}.o: ${EXERCISE}.c
	@mkdir -p ${BIN_DIR}
	cc ${CFLAGS} -c $^ -o $@

.PHONY: all clean fclean re
