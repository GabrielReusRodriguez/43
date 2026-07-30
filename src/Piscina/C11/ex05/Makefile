NAME=do-op.out
EXERCISE=ft_is_sort
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
${NAME}: ${BIN_DIR}/ft_arithmetic.o ${BIN_DIR}/ft_do_op.o ${BIN_DIR}/ft_put.o ${BIN_DIR}/ft_atoi.o
	cc ${CFLAGS} $^ -o ${NAME}

#Compile every .c file
${BIN_DIR}/%.o: %.c
	@mkdir -p ${BIN_DIR}
	cc ${CFLAGS} -c $^ -o $@

#${BIN_DIR}/${TEST}.o: ${SRC_DIR}/${TEST}.c
#	@mkdir -p ${BIN_DIR}
#	cc ${CFLAGS} -c $^ -o $@

.PHONY: all clean fclean re