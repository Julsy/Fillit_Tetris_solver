# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgutniko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 11:10:44 by lgutniko          #+#    #+#              #
#    Updated: 2016/10/24 14:12:47 by iiliuk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
FLAG = -Wall -Wextra -Werror
SRC = main.c error_check.c grid.c minos_split.c work_with_grid.c ft_strsplit.c recursion.c helper.c
OBJ = $(SRC:.c=.o)

$(NAME):
	$(CC) $(FLAG) -c $(SRC)
	$(CC) $(FLAG) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

.PHONY: all clean fclean re