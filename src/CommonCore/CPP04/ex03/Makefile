NAME= ex03

OBJ_DIR = ./obj
CPP_FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address -MMD -MP -std=c++98

SRC= 	main.cpp			\
		AMateria.cpp		\
		Character.cpp		\
		Cure.cpp			\
		Ice.cpp				\
		MateriaSource.cpp


OBJ=	$(patsubst %.cpp, ${OBJ_DIR}/%.o, ${SRC})
DEP=	$(patsubst %.cpp, ${OBJ_DIR}/%.d, ${SRC})

all : ${NAME}

${NAME}: ${OBJ}
	c++ ${CPP_FLAGS} ${OBJ} -o ${NAME}

${OBJ_DIR}/%.o : %.cpp Makefile
	@mkdir -p ${OBJ_DIR}
	c++ ${CPP_FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR}
	rm -rf ${OBJ_DIR}

fclean : clean 
	rm -rf ${NAME}

re: fclean all

-include ${DEP}

.PHONY : all clean fclean re