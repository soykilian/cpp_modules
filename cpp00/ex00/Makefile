# Name of the program built
NAME				:=		megaphone

# List of sources
SRCS				:=		./megaphone.cpp
OBJS				:=		${SRCS:.cpp=.o}

# Compiler
CC					:=		c++

# Flags - compilation
FLAGS_COMP			:= 		-std=c++98 -Werror -Wextra -Wall -pedantic

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Others commands
RM					:=		rm -rf

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS			:=		[$(_GREEN)SUCCESS$(_RESET)]

# General functions
all:						init $(NAME)
							@ printf "$(_SUCCESS) Compilation done\n"

init:
							@ printf "$(_INFO) Initialize $(NAME)\n"

$(NAME):					$(OBJS)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS)


.cpp.o:
							@ $(CC) $(FLAGS_COMP) -c $< -o $@

clean:
							@ $(RM) $(OBJS)
							@ printf "$(_INFO) Deleted files and directory\n"

fclean:						clean
							@ $(RM) $(NAME)

re:							fclean all

# Debugging functions

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						re

.PHONY:						all clean fclean re


