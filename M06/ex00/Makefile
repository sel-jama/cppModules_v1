# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 02:44:31 by sel-jama          #+#    #+#              #
#    Updated: 2024/02/27 09:51:30 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp ScalarConverter.cpp Char.cpp Double.cpp Float.cpp Int.cpp utils.cpp

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++ -std=c++98

NAME = convert

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all