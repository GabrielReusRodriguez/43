NAME = ex04

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC_FILES = main				\
			ReaderFileHandler	\
			WritterFileHandler	\
			StringHandler		

OBJ_DIR = ./obj

SRC = $(addsuffix .cpp , ${SRC_FILES})
OBJ = $(addsuffix .o, $(addprefix ${OBJ_DIR}/, ${SRC_FILES}))
DEP = $(addsuffix .d, $(addprefix ${OBJ_DIR}/, ${SRC_FILES}))

all : ${NAME}

${NAME}: ${OBJ}
	c++ ${CPP_FLAGS} ${OBJ} -o ${NAME}

${OBJ_DIR}/%.o: %.cpp Makefile
	mkdir -p ${OBJ_DIR}
	c++ ${CPP_FLAGS} -c $< -o $@

-include ${DEP}

clean: 
	rm -f ${OBJ_DIR}/*.o
	rm -f ${OBJ_DIR}/*.d

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re fclean clean