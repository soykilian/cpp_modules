NAME	= PmergeMe

CC		= c++

CFLAGS	= -std=c++98 -Werror -Wextra -Wall -pedantic -fsanitize=address -g3

SRCS	= PmergeMe.cpp main.cpp

OBJS	= ${SRCS:.cpp=.o}

RM		= rm -rf

all: ${NAME}

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

clean:
		@${RM} ${OBJS} *.dSYM

fclean:		clean
		@${RM} ${NAME}

bonus: all

re:		fclean all

.PHONY:	clean re fclean bonus all
