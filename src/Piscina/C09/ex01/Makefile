
NAME=libft.a
SRC_FOLDER=./srcs
INC_FOLDER=./includes
CFLAGS=-Wall -Wextra -Werror 

SRC_FILES := $(wildcard $(SRC_FOLDER)/*.c)
OBJ_FILES := $(SRC_FILES:%.c=%.o)


all: ${NAME}

clean:
	rm -f ${SRC_FOLDER}/*.o

fclean: clean
	rm -f ./*.a

re: fclean all

${NAME}: ${OBJ_FILES} 
	ar -crs ${NAME} ${OBJ_FILES}

${SRC_FOLDER}/%.o: ${SRC_FOLDER}/%.c
	cc ${CFLAGS} -I ${INC_FOLDER} -c $< -o $@

.PHONY: all clean fclean re
