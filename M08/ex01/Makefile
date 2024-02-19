SRCS = main.cpp Span.cpp

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Wextra -Werror

CC = c++ -std=c++98

NAME = Span

HEADERS = Span.hpp

all: ${NAME}

${NAME}: ${OBJS} ${HEADERS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all