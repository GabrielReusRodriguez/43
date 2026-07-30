NAME=test_ex04.out
EXERCISE=ft_str_is_lowercase
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
${NAME}: ${BIN_DIR}/${EXERCISE}.o ${BIN_DIR}/${TEST}.o
	cc ${CFLAGS} $^ -o ${NAME}

#Compile every .c file
${BIN_DIR}/${EXERCISE}.o: ${EXERCISE}.c
	@mkdir -p ${BIN_DIR}
	cc ${CFLAGS} -c $^ -o $@

${BIN_DIR}/${TEST}.o: ${SRC_DIR}/${TEST}.c
	@mkdir -p ${BIN_DIR}
	cc ${CFLAGS} -c $^ -o $@

.PHONY: all clean fclean re