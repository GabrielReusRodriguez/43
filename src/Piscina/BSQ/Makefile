NAME=bsq
CFLAGS=-Wall -Werror -Wextra
SRC_FOLDER=./src
INC_FOLDER=./inc
OBJ_FOLDER=./obj

#Comentario

all:${NAME}

${NAME}: ${OBJ_FOLDER}/bsq.o ${OBJ_FOLDER}/ft_buffer.o ${OBJ_FOLDER}/ft_first_line.o ${OBJ_FOLDER}/ft_map.o ${OBJ_FOLDER}/ft_numbers.o\
		 ${OBJ_FOLDER}/ft_rectangle.o ${OBJ_FOLDER}/ft_string.o  ${OBJ_FOLDER}/ft_put.o ${OBJ_FOLDER}/ft_line.o
	cc -o ${NAME} $^


${OBJ_FOLDER}/%.o: ${SRC_FOLDER}/%.c
	mkdir -p ${OBJ_FOLDER}
	cc ${CFLAGS} -I ${INC_FOLDER} -c $^ -o $@

clean:
	@rm -rf ./obj/*.o

fclean: clean
	@rm ./${NAME}

re: fclean all

.PHONY: all clean fclean re

