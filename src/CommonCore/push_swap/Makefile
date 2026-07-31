NAME=push_swap
CFLAGS=-Wall -Wextra -Werror -MMD -MP
CC=cc
LIBFT_DIR=../libft
LIBFT=${LIBFT_DIR}/bin/libft.a
INC=-I src -I ${LIBFT_DIR}/include
SRC_DIR=./src
BIN_DIR=./bin

SRC_FILES=	${SRC_DIR}/ft_stack.c			\
			${SRC_DIR}/ft_stack2.c			\
			${SRC_DIR}/ft_validations.c		\
			${SRC_DIR}/ft_primitives_sx.c	\
			${SRC_DIR}/ft_primitives_px.c	\
			${SRC_DIR}/ft_primitives_rx.c	\
			${SRC_DIR}/ft_primitives_rrx.c	\
			${SRC_DIR}/ft_actions.c			\
			${SRC_DIR}/ft_sort.c			\
			${SRC_DIR}/ft_push_swap.c

OBJ_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.o)
DEP_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.d)

all: ${NAME}

${NAME}: ${BIN_DIR} ${LIBFT} ${OBJ_FILES}
	${CC} ${CFLAGS} -o $@ ${OBJ_FILES} ${LIBFT}

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

${LIBFT}:
	make -C ${LIBFT_DIR} all

${BIN_DIR}/%.o: ${SRC_DIR}/%.c Makefile
	${CC} ${CFLAGS} ${INC} -o $@ -c $<

clean:
	rm -f ${BIN_DIR}/*.o ${BIN_DIR}/*.d

fclean: clean
	rm -f ${NAME}

re: fclean all

-include ${DEP_FILES}

.PHONY: all clean fclean re
