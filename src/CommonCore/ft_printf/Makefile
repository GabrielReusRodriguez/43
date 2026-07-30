# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 02:39:39 by greus-ro          #+#    #+#              #
#    Updated: 2024/11/02 19:20:16 by gabriel          ###   ########.fr        #
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

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP

ifdef	CSANITIZE
	SANITIZE_FLAGS	= -g3 -fsanitize=address -fsanitize=leak
endif

SRC		= 	ft_format.c				\
			ft_format_padding.c		\
			ft_format_prefix.c		\
			ft_width.c				\
			ft_padding_utils.c		\
			ft_precision.c			\
			ft_printf_char.c		\
			ft_printf_dec.c			\
			ft_printf_hex.c			\
			ft_printf_int.c			\
			ft_printf_low_hex.c		\
			ft_printf_percent.c		\
			ft_printf_ptr.c			\
			ft_printf_str.c			\
			ft_printf_up_hex.c		\
			ft_printf_usgn.c		\
			ft_printf.c
			
HDR		=	ft_printf.h

SRCS	= $(patsubst %.c, ${SRC_DIR}/%.c, ${SRC})
HDRS	= $(patsubst %.h, ${INC_DIR}/%.h, ${HDR})
OBJS	= $(patsubst %.c, ${OBJ_DIR}/%.o, ${SRC})
DEPS	= $(patsubst %.c, ${OBJ_DIR}/%.d, ${SRC})

all: folders compile

compile: 
	@echo "\t${CYAN}Making libft...${RST}"

	@make --no-print-directory all -C ${LIBFT_DIR}
	@echo "\t${CYAN}Making ${NAME}...${RST}"
	@make --no-print-directory ${BIN_DIR}/${NAME}

${BIN_DIR}/${NAME}: ${LIBFT_DIR} ${OBJS} Makefile
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

.PHONY: all clean fclean re folders compile