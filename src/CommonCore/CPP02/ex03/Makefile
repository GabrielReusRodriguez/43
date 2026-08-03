NAME = ex03

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP

OBJ_DIR = ./obj

SRC_FILES = main	\
			bsp		\
			Fixed	\
			Point

SRC = $(addsuffix .cpp , ${SRC_FILES})
OBJ = $(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${SRC_FILES}))
DEP = $(addprefix ${OBJ_DIR}/, $(addsuffix .d, ${SRC_FILES}))

all: ${NAME}

${NAME}: ${OBJ}
	c++ ${CPP_FLAGS} ${OBJ} -o ${NAME}

${OBJ_DIR}/%.o : %.cpp Makefile
	@mkdir -p ${OBJ_DIR}
	c++ ${CPP_FLAGS} -c $< -o $@

-include ${DEP}

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${OBJ_DIR}/*.d

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re fclean clean