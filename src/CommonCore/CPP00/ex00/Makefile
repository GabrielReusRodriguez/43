NAME 		= 	megaphone

CPPFLAGS	+=	-Wall -Werror -Wextra -std=c++98 -MMD -MP
SRC			=	megaphone

OBJS		= $(addsuffix .o, ${SRC})
DEPS		= $(addsuffix .d, ${SRC})

all: ${NAME}

${NAME} : ${OBJS}
	c++ ${CPPFLAGS} ${OBJS} -o ${NAME}

%.o : %.cpp Makefile
	c++ ${CPPFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${DEPS}

fclean: clean
	rm -f ${NAME}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re
