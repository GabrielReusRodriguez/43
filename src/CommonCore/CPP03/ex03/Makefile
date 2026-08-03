NAME=ex03

#Wshadow: -Wshadow option produces a warning when explicitly capturing class member using the same name
#Warn whenever a local variable or type declaration shadows another variable, parameter, type, class member (in C++), 
#or instance variable (in Objective-C) or whenever a built-in function is shadowed. 
#Note that in C++, the compiler warns if a local variable shadows an explicit typedef, but not if it shadows a struct/class/enum. 
#If this warning is enabled, it includes also all instances of local shadowing. 
#This means that -Wno-shadow=local and -Wno-shadow=compatible-local are ignored when -Wshadow is used. Same as -Wshadow=global. 

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP -Wshadow
SRC_FILES = main	\
			ClapTrap	\
			DiamondTrap	\
			ScavTrap	\
			FragTrap

OBJ_DIR = ./obj

SRC = $(addsuffix .cpp, ${SRC_FILES})
OBJ = $(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${SRC_FILES}))
DEP = $(addprefix ${OBJ_DIR}/, $(addsuffix .d, ${SRC_FILES}))

all: ${NAME}

${NAME}: ${OBJ}
	c++ ${CPP_FLAGS} ${OBJ} -o ${NAME}

${OBJ_DIR}/%.o : %.cpp Makefile
	@mkdir -p ${OBJ_DIR}
	c++ ${CPP_FLAGS} -c $< -o $@

-include ${DEP}

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re fclean clean