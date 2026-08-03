NAME=ex00

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP
SRC_FILES = main	\
			ClapTrap

OBJ_DIR = ./obj

SRC = $(addsuffix .cpp, ${SRC_FILES})
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
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re fclean clean