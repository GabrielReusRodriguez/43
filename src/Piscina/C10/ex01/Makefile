NAME=ft_cat.out
CFLAGS=-Wall -Werror -Wextra

all: ${NAME}

${NAME}: ft_cat.c ft_string.c ft_buffer.c ft_file.c
	cc ${CFLAGS} -o ${NAME} $^ 

clean:
	rm ./*.o

fclean: clean 
	rm ./${NAME}

.PHONY: all clean fclean
