NAME=printf.out

OBJ_DIR = ./obj
LIBFT_LIB_DIR = ../../libft/bin/
LIBFT_INC_DIR = ../../libft/include
PRINTF_LIB_DIR = ../bin/
PRINTF_INC_DIR = ../include

CFLAGS = -Wall -Werror -Wextra 

ifdef	CSANITIZE
	SANITIZE_FLAGS	= -g -O3 -fsanitize=address -fsanitize=leak
endif

SRC = main.c
OBJS = $(patsubst %.c, ${OBJ_DIR}/%.o, ${SRC})
DEPS = $(patsubst %.c, ${OBJ_DIR}/%.d, ${SRC})

BUILD_DIRS = ${OBJ_DIR}


all: ${BUILD_DIRS} ${NAME}

${BUILD_DIRS}:
	@mkdir -p ${OBJ_DIR}

${NAME}: ${OBJS}
	cc -L ${LIBFT_LIB_DIR} -L ${PRINTF_LIB_DIR} -o ${NAME} ${OBJS} -lftprintf -lft

${OBJ_DIR}/%.o : %.c  Makefile
	cc ${CFLAGS} ${SANITIZE_FLAGS} -c $< -I ${LIBFT_INC_DIR} -I ${PRINTF_INC_DIR} -o $@

clean: 
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${NAME}

-include ${DEPS}

.PHONY: all clean fclean re