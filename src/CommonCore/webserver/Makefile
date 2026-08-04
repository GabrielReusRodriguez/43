APP			=	webserv

SRC_DIR		= ./src
BIN_DIR		= ./bin
INC_DIR		= ./inc
OBJ_DIR		= ./obj

PROJ_DIRS	= ${BIN_DIR} ${OBJ_DIR}

CPP			= g++
CPP_FLAGS	= -std=c++98 -Wall -Wextra -Werror -MMD -MP -g3 -fsanitize=address

SRC			=	main.cpp							\
				config/Config.cpp					\
				debugger/Debugger.cpp				\
				engine/WebServer_basics.cpp			\
				engine/WebServer_logic.cpp			\
				exceptions/Exception.cpp			\
				exceptions/NetworkException.cpp		\
				services/network/NetworkService.cpp	\

SRCS		= $(patsubst %.cpp,${SRC_DIR}/%.cpp, ${SRC})
OBJS		= $(patsubst %.cpp,${OBJ_DIR}/%.o, ${SRC})
DEPS		= $(patsubst %.cpp,${OBJ_DIR}/%.d, ${SRC})

all:	${BIN_DIR}/${APP}

${BIN_DIR}/${APP}: ${PROJ_DIRS} ${OBJS}
	${CPP} ${CPP_FLAGS}  ${OBJS} -o $@ 

${PROJ_DIRS}:
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/config
	@mkdir -p ${OBJ_DIR}/debugger
	@mkdir -p ${OBJ_DIR}/engine
	@mkdir -p ${OBJ_DIR}/exceptions
	@mkdir -p ${OBJ_DIR}/services
	@mkdir -p ${OBJ_DIR}/services/network
	@mkdir -p ${OBJ_DIR}/services/requestHandler
	@mkdir -p ${BIN_DIR}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.cpp Makefile
	${CPP} ${CPP_FLAGS} -I ${INC_DIR} -c $< -o $@ 

clean:
	@rm -rf ${OBJ_DIR}

fclean: clean
	@rm -rf ${BIN_DIR}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re