NAME = philo
#CDEBUG = -g3 -fsanitize=address
#CDEBUG 			= -g3
PTHREAD_FLAG 	= -pthread
CFLAGS			= -Wall -Wextra -Werror ${PTHREAD_FLAG}
DEPFLAGS		= -MMD -MP

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

SRC_FILES =		args				\
				fork_utils			\
				main				\
				philo_die			\
				philo_eat			\
				philo_life			\
				philo_mutex			\
				philo_sleep			\
				philo_think			\
				philo_utils			\
				printer				\
				rules				\
				simulation_mutex	\
				simulation_utils	\
				supervisor			\
				threads				\
				timestamp			\
				utils

ifdef SANITIZE
	CSANITIZE = -g3 -fsanitize=${SANITIZE}
else
	CSANITIZE = 
endif

SRC = $(addsuffix .c, $(addprefix ${SRC_DIR}/, ${SRC_FILES}))
OBJ = $(addsuffix .o, $(addprefix ${OBJ_DIR}/, ${SRC_FILES}))
DEP = $(addsuffix .d, $(addprefix ${OBJ_DIR}/, ${SRC_FILES}))

all: $(NAME)

$(NAME): ${OBJ} 
	cc ${OBJ} ${CSANITIZE} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c Makefile
	@mkdir -p ${OBJ_DIR}
	cc $(CFLAGS) ${DEPFLAGS} -I ${INC_DIR} -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)/*.d

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re