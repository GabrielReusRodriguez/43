NAME=philo
#CDEBUG = -g3 -fsanitize=address
#CDEBUG = -g3
#PTHREAD_FLAG = -lpthread
CDEBUG =
CFLAGS=-Wall -Wextra -Werror -MMD -MP ${CDEBUG} ${PTHREAD_FLAG}

SRC_DIR=.
OBJ_DIR=./obj
INC_DIR=./inc

SRC_FILES=	ft_args.c				\
			ft_forkproc.c			\
			ft_forkproc2.c			\
			ft_log.c				\
			ft_philosopher.c		\
			ft_philosopher2.c		\
			ft_philosopher3.c		\
			ft_rules.c				\
			ft_semaphores.c			\
			ft_sleep.c				\
			ft_table.c				\
			ft_timestamp.c			\
			ft_threads.c			\
			ft_threads2.c			\
			ft_utils_atoi.c			\
			ft_utils_ctoi.c			\
			ft_utils_contains_num.c	\
			ft_utils_isdigit.c		\
			ft_utils_itoa.c			\
			ft_utils_print.c		\
			ft_utils_strjoin.c		\
			ft_utils_strlen.c		\
			philo_bonus.c

#BONUS_SRC_FILES=	

OBJ_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
DEP_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.d)

OBJ_BONUS_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
DEP_BONUS_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.d)

all: $(NAME)

bonus: $(OBJ_DIR) ${OBJ_BONUS_FILES}
	cc ${OBJ_FILES} -o ${NAME}
	@touch bonus

$(NAME): $(OBJ_DIR) $(OBJ_FILES) 
	cc ${OBJ_FILES} -o ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	cc $(CFLAGS) -I${INC_DIR} -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)/*.d
	rm -f ./bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)

.PHONY: all clean fclean re