# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pierre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/12 19:19:55 by Pierre            #+#    #+#              #
#    Updated: 2015/03/12 19:26:00 by Pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hashcode

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/*
INC = include/

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -I$(INC)

clean: rm *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
