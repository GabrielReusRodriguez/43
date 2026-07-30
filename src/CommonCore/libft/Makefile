# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 01:34:53 by greus-ro          #+#    #+#              #
#    Updated: 2024/11/04 20:14:50 by gabriel          ###   ########.fr        #
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
# Compiler stuff
################################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
ifdef	CSANITIZE
	SANITIZE_FLAGS	=	-g3 -fsanitize=address -fsanitize=leak
endif
DEP_FLAGS		=	-MMD -MP
CFLAGS			+=	${DEP_FLAGS}

################################################################################
#Folders
################################################################################

SRC_DIR		=	./src
INC_DIR		=	./include
BUILD_DIR	=	./build
BIN_DIR		=	./bin

################################################################################
# Name of exec
################################################################################

NAME		=	libft.a

################################################################################
# Files
################################################################################

SRC			=	ft_atoi.c			\
				ft_atol.c			\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_dtoh.c			\
				ft_error.c			\
				ft_htoa.c			\
				ft_iputchar_fd.c	\
				ft_iputendl_fd.c	\
				ft_iputnbr_fd.c		\
				ft_iputstr_fd.c		\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_islower.c		\
				ft_isupper.c		\
				ft_isprint.c		\
				ft_itoa.c			\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_pointer.c		\
				ft_putchar_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_putstr_fd.c		\
				ft_split.c			\
				ft_strchr.c			\
				ft_strdup.c			\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strmapi.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_istrchr.c		\
				ft_strtrim.c		\
				ft_substr.c			\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_utoa.c			\
				ft_lstadd_front_bonus.c		\
				ft_lstadd_back_bonus.c		\
				ft_lstclear_bonus.c			\
				ft_lstcontains.c			\
				ft_lstdelone_bonus.c		\
				ft_lstdel_back.c			\
				ft_lstdel_front.c			\
				ft_lstiter_bonus.c			\
				ft_lstlast_bonus.c			\
				ft_lstmap_bonus.c			\
				ft_lstnew_bonus.c			\
				ft_lstsize_bonus.c

HEADERS		= libft.h

SRCS		= 	$(patsubst %.c, ${SRC}/%.c, ${SRC})
OBJS		= 	$(patsubst %.c, ${BUILD_DIR}/%.o, ${SRC})
DEPS		= 	$(patsubst %.c, ${BUILD_DIR}/%.d, ${SRC})

################################################################################
# Rules 
################################################################################

all					:	folders ${BIN_DIR}/${NAME}

${BIN_DIR}/${NAME}	:	${OBJS}
	@echo "\t${CYAN}Linking ${NAME}${RST}"
	@ar -rcs ${BIN_DIR}/${NAME} ${OBJS}
	
${BUILD_DIR}/%.o	:	${SRC_DIR}/%.c  Makefile
	@echo "\t${YELLOW}Compiling ${RST} $<"
#	@mkdir -p ${BUILD_DIR}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} -I ${INC_DIR} -c $< -o $@ 
#	@${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@ 

clean				:
	@echo "${RED}${NAME} -> Cleaning build folder${RST}"
	@rm -rf ${BUILD_DIR}

fclean: clean 
	@echo "${RED}${NAME} -> Cleaning ${NAME}${RST}"
#	@rm -f ${NAME}
	@rm -rf ${BIN_DIR}

folders:
	@mkdir -p ${BUILD_DIR}
	@mkdir -p  ${BIN_DIR}

re: fclean all

#bonus:${BONUS_OBJ_FILES} ${LIBFT_OBJ_FILES}
#	ar -rcs ${NAME} ${LIBFT_OBJ_FILES} ${BONUS_OBJ_FILES}
#	@touch bonus

-include ${DEPS}

################################################################################
# Phony
################################################################################

.PHONY: all clean fclean re
