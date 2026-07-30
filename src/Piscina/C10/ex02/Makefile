NAME=ft_tail.out
CFLAGS=-Wall -Werror -Wextra

all: ${NAME}

${NAME}: ft_tail.c ft_string.c ft_buffer.c ft_args.c ft_put.c ft_numbers.c ft_tail_program.c 
	cc ${CFLAGS} -o ${NAME} $^ 

clean:
	rm ./*.o

fclean: clean 
	rm ./${NAME}

.PHONY: all clean fclean
