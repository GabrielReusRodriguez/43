NAME=test_ex01.out
EXERCISE=ft_print_params
TEST=test

CFLAGS= -Wall -Wextra -Werror 
SRC_DIR=./src
BIN_DIR=./bin

all: ${NAME}

clean:
	rm ${BIN_DIR}/*

fclean: clean
	rm ./${NAME}

re: fclean all

#Compile tests.
${NAME}: ${BIN_DIR}/${EXERCISE}.o
	cc ${CFLAGS} $^ -o ${NAME}

#Compile every .c file
${BIN_DIR}/${EXERCISE}.o: ${EXERCISE}.c
	@mkdir -p ${BIN_DIR}
	cc ${CFLAGS} -c $^ -o $@

${BIN_DIR}/${TEST}.o: ${EXERISE}.c
	@mkdir -p ${BIN_DIR}
	cc ${CFLAGS} -c $^ -o $@

.PHONY: all clean fclean re