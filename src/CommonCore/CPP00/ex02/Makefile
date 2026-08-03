NAME = account

CPP_FLAGS += -Wall -Wextra -Werror -std=c++98 -MMD -MP

OBJ_DIR	= ./obj

SRC_FILES =	Account	\
			tests

SRCS = $(addsuffix .cpp, ${SRC_FILES})
DEPS = $(addprefix ${OBJ_DIR}/, $(addsuffix .d, ${SRC_FILES}))
OBJS = $(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${SRC_FILES}))

all:	${NAME}

${NAME} : ${OBJS}
	c++ ${CPP_FLAGS} ${OBJS} -o $@

${OBJ_DIR}/%.o : %.cpp Makefile
	@mkdir -p ${OBJ_DIR}
	c++ ${CPP_FLAGS} -c $< -o $@

-include ${DEPS}

clean :
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re clean fclean