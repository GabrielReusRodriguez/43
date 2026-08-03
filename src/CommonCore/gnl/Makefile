# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 02:39:39 by greus-ro          #+#    #+#              #
#    Updated: 2026/08/03 18:42:00 by greus-ro         ###   ########.fr        #
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

INC_DIR=./include
OBJ_DIR=./build
BIN_DIR=./bin
SRC_DIR=./src
LIBFT_DIR = ../libft
LIBFT_LIB = ${LIBFT_DIR}/bin/libft.a

################################################################################
# Compiler stuff
################################################################################

NAME		= libgnl.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP
DFLAGS		= -D BUFFER_SIZE=30

ifdef	CSANITIZE
	SANITIZE_FLAGS	= -g3 -fsanitize=address -fsanitize=leak
endif

SRC		= 	ft_get_next_line.c 				\
			ft_get_next_line_bonus.c

HDR		=	ft_get_next_line.h

SRCS	= $(patsubst %.c, ${SRC_DIR}/%.c, ${SRC})
HDRS	= $(patsubst %.h, ${INC_DIR}/%.h, ${HDR})
OBJS	= $(patsubst %.c, ${OBJ_DIR}/%.o, ${SRC})
DEPS	= $(patsubst %.c, ${OBJ_DIR}/%.d, ${SRC})

all: folders ${BIN_DIR}/${NAME}

${LIBFT_LIB}:
	@echo "\t${CYAN}Making libft...${RST}"
	@make --no-print-directory all -C ${LIBFT_DIR}

${BIN_DIR}/${NAME}: ${LIBFT_LIB} ${OBJS} Makefile
	@echo "\t${CYAN}Linking ${NAME}${RST}"
	@ar -rcs ${BIN_DIR}/${NAME} ${OBJS}

${OBJ_DIR}/%.o:${SRC_DIR}/%.c Makefile
	@echo "\t${YELLOW}Compiling ${RST} $<"
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${DFLAGS} -I ${INC_DIR} -I ${LIBFT_DIR}/include -o $@ -c $<

clean:
	@make --no-print-directory clean -C ${LIBFT_DIR}
	@rm -rf ${OBJ_DIR}

fclean: clean
	@make --no-print-directory fclean -C ${LIBFT_DIR}
	@rm -rf ${BIN_DIR}

re: fclean all

folders:
	@mkdir -p ${BIN_DIR}
	@mkdir -p ${OBJ_DIR}

-include ${DEPS}

.PHONY: all clean fclean re folders
