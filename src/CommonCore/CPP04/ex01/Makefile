NAME = ex01

CPP_FLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -g1 -fsanitize=address

OBJ_DIR = ./obj

SRC = main.cpp	\
			Animal.cpp	\
			Cat.cpp		\
			Dog.cpp		\
			Brain.cpp

OBJ=	$(patsubst %.cpp, ${OBJ_DIR}/%.o, ${SRC})
DEP=	$(patsubst %.cpp, ${OBJ_DIR}/%.d, ${SRC})

all: ${NAME}

${NAME}: ${OBJ}
	c++ ${CPP_FLAGS} ${OBJ} -o ${NAME}

${OBJ_DIR}/%.o : %.cpp Makefile
	@mkdir -p ${OBJ_DIR}
	c++ ${CPP_FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR}
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all

-include ${DEP}

.PHONY: all re clean fclean