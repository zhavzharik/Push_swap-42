# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 20:22:10 by abridger          #+#    #+#              #
#    Updated: 2021/09/08 16:47:19 by abridger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	push_swap.c		\
		check_argv.c	\
		parser.c		\
		ft_atoi.c		\
		ft_str.c		\
		sorting.c		\
		operations_1.c	\
		operations_2.c	\
		ft_lst.c		\
		structure.c		\
		game_1.c		\
		clear.c			\
		game_2.c		\
		short_stack.c	\
		game_3.c




OBJ = $(SRC:.c=.o)

CC = gcc

REM = rm -f

INCL = push_swap.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c $(INCL) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	$(REM) $(OBJ)

fclean : clean
	$(REM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
