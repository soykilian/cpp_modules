# Name of the program built
NAME				:=		phonebook

# List of sources
SRCS				:=		PhoneBook.cpp main.cpp Contact.cpp
OBJS				:=		${SRCS:.cpp=.o}

# Compiler
CC					:=		c++

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Flags - compilation

CXXFLAGS  = -std=c++98 -Werror -Wextra -Wall -pedantic
FLAGS_COMP			:= 		$((CXXFLAGS) $(FLAG_MEM_LEAK)

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


%.o: %.cpp
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

