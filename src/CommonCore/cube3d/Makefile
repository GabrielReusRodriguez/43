# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 19:39:15 by gabriel           #+#    #+#              #
#    Updated: 2026/08/03 19:10:00 by gabriel          ###   ########.fr        #
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
#Folders
################################################################################

SRC_DIR			=	./src
INC_DIR			=	./include
BUILD_DIR		=	./build
LIBFT_DIR		=	../libft
LIBFT_LIB		=	${LIBFT_DIR}/bin/libft.a
GNL_DIR			=	../gnl
GNL_LIB			=	${GNL_DIR}/bin/libgnl.a
MINILIBX_DIR	=	./mlx42
MLX_LIB			=	${MINILIBX_DIR}/build/libmlx42.a

################################################################################
# Compiler stuff
################################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
ifdef	CSANITIZE
	SANITIZE_FLAGS	= -g -O3 -fsanitize=address -fsanitize=leak
endif
DEBUG_FLAG		=	-D DEBUG_FLAG=0
DEP_FLAGS		=	-MMD -MP
CFLAGS			+=	${DEP_FLAGS}
LIBS			=	-lm -lgnl -lft -lmlx42 -ldl -lglfw -pthread
LIBS_FOLDERS	=	-L${LIBFT_DIR}/bin -L${MINILIBX_DIR}/build -L${GNL_DIR}/bin

################################################################################
# Name of exec
################################################################################

NAME	=	cube3d

################################################################################
# Files
################################################################################

SRC		=	main.c							\
			camera.c						\
			color.c							\
			error.c							\
			screen.c

SRC		+=	config/config_header_parser.c		\
			config/config_loader.c				\
			config/config_map_parser.c			\
			config/config_validator_map.c		\
			config/config_validator.c			\
			config/config.c

SRC		+=	dda/dda.c

SRC		+=	engine/engine.c						\
			engine/engine_mlx_config.c			\
			engine/engine_render.c				\
			engine/engine_textures.c

SRC		+=	events/handler_key_events.c			\
			events/handler_destroy_event.c		\
			events/handler_resize_event.c

SRC		+=	flooding/flooding.c					\
			flooding/flooding_neighbours.c		\
			flooding/flooding_utils.c

SRC		+=	geometry/point.c					\
			geometry/radiants.c					\
			geometry/vector_arithmetic.c		\
			geometry/vector.c

SRC		+=	map/map.c							\
			map/map_loader.c					\
			map/map_parser.c					\
			map/tile.c


HEADERS			=	camera.h		\
					color.h			\
					config.h		\
					constants.h		\
					dda.h			\
					engine.h		\
					error.h			\
					events.h		\
					flooding.h		\
					map.h			\
					player.h		\
					point.h			\
					radiants.h		\
					screen.h		\
					texture.h		\
					tile.h			\
					types.h			\
					vector.h

SRCS			=	$(addprefix ${SRC_DIR}/, ${SRC})
OBJS			=	$(patsubst %.c, ${BUILD_DIR}/%.o, ${SRC})
DEPS			=	$(patsubst %.c, ${BUILD_DIR}/%.d, ${SRC})
HDRS			=	$(addprefix ${INC_DIR}/, ${HEADERS})

################################################################################
# Rules
################################################################################

all				:	${BUILD_DIR} compile

${NAME}			:	${OBJS} ${LIBFT_LIB} ${GNL_LIB} ${MLX_LIB} Makefile
	@echo "${CYAN}Linking all together${RST}"
	${CC} ${CFLAGS} ${SANITIZE_FLAGS} -o ${NAME} ${OBJS} ${LIBS_FOLDERS} ${LIBS}
	@echo "$(GREEN)Binary $(NAME) compiled! $(RST)"

compile:
	@echo "${CYAN}Making libft...${RST}"
	@make --no-print-directory -C ${LIBFT_DIR}
	@echo "${CYAN}Making get_next_line...${RST}"
	@make --no-print-directory -C ${GNL_DIR}
	@echo "${CYAN}Making MLX42...${RST}"
	@cmake -S ${MINILIBX_DIR} -B ${MINILIBX_DIR}/build
	@cmake --build ${MINILIBX_DIR}/build -j4
	@echo "${CYAN}Making ${NAME}...${RST}"
	@make --no-print-directory ${NAME}

${LIBFT_LIB}:
	@make --no-print-directory -C ${LIBFT_DIR}

${GNL_LIB}:
	@make --no-print-directory -C ${GNL_DIR}

${MLX_LIB}:
	@cmake -S ${MINILIBX_DIR} -B ${MINILIBX_DIR}/build
	@cmake --build ${MINILIBX_DIR}/build -j4

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}
	mkdir -p ${BUILD_DIR}/config
	mkdir -p ${BUILD_DIR}/dda
	mkdir -p ${BUILD_DIR}/engine
	mkdir -p ${BUILD_DIR}/events
	mkdir -p ${BUILD_DIR}/flooding
	mkdir -p ${BUILD_DIR}/geometry
	mkdir -p ${BUILD_DIR}/map

${BUILD_DIR}/%.o	:	${SRC_DIR}/%.c Makefile
	@echo "\t${YELLOW}Compiling ${NAME} ->${RST} $<"
	@${CC} ${CFLAGS} -I${INC_DIR} -I${MINILIBX_DIR}/include -I${LIBFT_DIR}/include -I${GNL_DIR}/include ${DEBUG_FLAG} -c $< -o $@

clean			:
	@make --no-print-directory clean -C ${LIBFT_DIR}
	@make --no-print-directory clean -C ${GNL_DIR}
	@echo "${RED}Cleaning build folder${RST}"
	@rm -rf ${BUILD_DIR}

fclean			:	clean
	@make --no-print-directory fclean -C ${LIBFT_DIR}
	@make --no-print-directory fclean -C ${GNL_DIR}
	@echo "${RED}Cleaning ${NAME}${RST}"
	@rm -f ${NAME}

re				:	fclean all

norm:
	@norminette ${HDRS}
	@norminette ${SRCS}

-include ${DEPS}

################################################################################
# Phony
################################################################################

.PHONY	:	all clean fclean re norm
