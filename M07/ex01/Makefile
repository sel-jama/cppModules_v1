# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 10:10:58 by sel-jama          #+#    #+#              #
#    Updated: 2024/02/29 12:00:11 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Wextra -Werror

CC = c++ -std=c++98

NAME = Iter

HEADERS = Iter.hpp

all: ${NAME}

${NAME}: ${OBJS} ${HEADERS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all