# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 11:30:49 by jfritz            #+#    #+#              #
#    Updated: 2021/07/15 11:40:00 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = a.out

CFLAGS = -Wall -Wextra -Werror

OBJS := *.o
SRC = main.c

GNL = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

${NAME}:
	${CC} ${CFLAGS} ${SRC} $(GNL)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean ${NAME}