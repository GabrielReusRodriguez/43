# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 18:12:37 by gabriel           #+#    #+#              #
#    Updated: 2024/11/03 22:42:16 by gabriel          ###   ########.fr        #
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

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP

ifdef	CSANITIZE
	SANITIZE_FLAGS	= -g3 -fsanitize=address -fsanitize=leak
endif

SRC = 	pipex.c				\
		ft_child.c			\
		ft_environment.c	\
		ft_error.c			\
		ft_exec.c			\
		ft_fd.c				\
		ft_files.c			\
		ft_parent.c			\
		ft_path.c

HDR =	ft_child.h			\
		ft_environment.h	\
		ft_error.h			\
		ft_exec.h			\
		ft_fd.h				\
		ft_files.h			\
		ft_parent.h			\
		ft_path.h

SRCS = $(patsubst %.c,${SRC_DIR}/%.c, ${SRC})
OBJS = $(patsubst %.c,${OBJ_DIR}/%.o, ${SRC})
DEPS = $(patsubst %.c,${OBJ_DIR}/%.d, ${SRC})

all: ${PROJ_DIRS} ${BIN_DIR}/${NAME}


${LIBFT_LIB}:
	@echo "\t${CYAN}Making libft...${RST}"
	@make --no-print-directory all -C ${LIBFT_DIR} 

${GNL_LIB}:
	@echo "\t${CYAN}Making gnl...${RST}"
	@make --no-print-directory all -C ${GNL_DIR} 

${PROJ_DIRS}: 
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${BIN_DIR}

${BIN_DIR}/${NAME}: ${LIBFT_LIB} ${GNL_LIB} ${OBJS} Makefile
	@echo "${CYAN}Linking ${NAME}...${RST}"
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} -L ${LIBFT_DIR}/bin -L ${GNL_DIR}/bin -o ${BIN_DIR}/${NAME} ${OBJS} -lgnl -lft

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

.PHONY: all clean fclean re compile_libs update_libs