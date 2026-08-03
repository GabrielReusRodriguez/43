# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 22:28:56 by gabriel           #+#    #+#              #
#    Updated: 2026/08/02 20:45:20 by greus-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# Colours
################################################################################

RST				= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

################################################################################
# Folders
################################################################################

GNL_DIR		= ../gnl
GNL_LIB		= ${GNL_DIR}/bin/libgnl.a
LIBFT_DIR 	= ../libft
LIBFT_LIB 	= ${LIBFT_DIR}/bin/libft.a

SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
INC_DIR = ./include

PROJ_DIRS = ${OBJ_DIR} ${BIN_DIR}

################################################################################
# Compiler stuff
################################################################################

NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP

ifdef	CSANITIZE
	SANITIZE_FLAGS	= -g3 -fsanitize=address -fsanitize=leak
endif

LIBS_FLAG = -lreadline -lgnl -lft

SRC = 	main.c									\
		builtins/builtin_env.c					\
		builtins/builtin_echo.c					\
		builtins/builtin_export.c				\
		builtins/builtin_exit.c					\
		builtins/builtins_utils.c				\
		cmd/cmd.c								\
		cmd/cmd_fds_outputs.c					\
		cmd/cmd_fds_inputs.c					\
		cmd/cmd_params.c						\
		cmd/cmd_redirections.c					\
		cmd/cmd_utils.c							\
		env/env_utils.c							\
		env/env_var_getter.c					\
		env/environment.c						\
		env/env_to_char.c						\
		env/var_cache.c							\
		executor/executor_jobs.c				\
		executor/executor_cmd.c					\
		executor/executor_cmd_pipeline.c		\
		executor/executor_cmd_non_pipeline.c	\
		executor/executor_execve.c				\
		executor/executor_logic.c				\
		expansor/expansor.c						\
		expansor/expansor_cmd.c					\
		expansor/expansor_utils.c				\
		file/fd.c								\
		file/pipes.c							\
		job/job.c								\
		job/job_utils.c							\
		path/path_permission.c					\
		path/path_pathfile.c					\
		path/path_types.c						\
		redirect/redirect_utils.c				\
		redirect/redirect.c						\
		shell/minishell.c						\
		shell/minishell_utils.c					\
		tokenizer/token.c						\
		tokenizer/tokenizer.c					\
		tokenizer/tokenizer_utils.c				\
		utils/pair.c							\
		utils/str_appends.c						\
		utils/str_fragment.c					\
		utils/str_join_components.c				\
		utils/str_unquote.c


SRCS = $(patsubst %.c,${SRC_DIR}/%.c, ${SRC})
OBJS = $(patsubst %.c,${OBJ_DIR}/%.o, ${SRC})
DEPS = $(patsubst %.c,${OBJ_DIR}/%.d, ${SRC})

all: ${PROJ_DIRS} ${BIN_DIR}/${NAME}

${PROJ_DIRS}:
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/builtins/
	@mkdir -p ${OBJ_DIR}/cmd/
	@mkdir -p ${OBJ_DIR}/env/
	@mkdir -p ${OBJ_DIR}/executor/
	@mkdir -p ${OBJ_DIR}/expansor/
	@mkdir -p ${OBJ_DIR}/file/
	@mkdir -p ${OBJ_DIR}/job
	@mkdir -p ${OBJ_DIR}/redirect
	@mkdir -p ${OBJ_DIR}/shell/
	@mkdir -p ${OBJ_DIR}/tokenizer/
	@mkdir -p ${OBJ_DIR}/utils/
	@mkdir -p ${OBJ_DIR}/path/
	@mkdir -p ${BIN_DIR}


${LIBFT_LIB}:
	@echo "\t${CYAN}Making libft...${RST}"
	@make --no-print-directory all -C ${LIBFT_DIR} 

${GNL_LIB}:
	@echo "\t${CYAN}Making gnl...${RST}"
	@make --no-print-directory all -C ${GNL_DIR} 
	
${BIN_DIR}/${NAME}: ${LIBFT_LIB} ${GNL_LIB} ${OBJS} Makefile
	@echo "${CYAN}Linking ${NAME}...${RST}"
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} -L ${LIBFT_DIR}/bin -L ${GNL_DIR}/bin -o ${BIN_DIR}/${NAME} ${OBJS} ${LIBS_FLAG}


${OBJ_DIR}/%.o : ${SRC_DIR}/%.c Makefile
	@echo "\t${YELLOW}Compiling ${RST} $<"
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} -I ${INC_DIR} -I ${LIBFT_DIR}/include -I ${GNL_DIR}/include -c $< -o $@ 

clean:
	@make --no-print-directory clean -C ${LIBFT_DIR}
	@make --no-print-directory clean -C ${GNL_DIR}
	@rm -rf ${OBJ_DIR}

fclean: clean
	@make --no-print-directory fclean -C ${LIBFT_DIR}
	@make --no-print-directory fclean -C ${GNL_DIR}
	@rm -rf ${BIN_DIR}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re