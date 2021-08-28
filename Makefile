# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 20:22:10 by abridger          #+#    #+#              #
#    Updated: 2021/08/28 16:10:32 by abridger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	push_swap.c		\
		check_argv.c	\
		parser.c		\
		ft_atoi.c		\
		ft_str.c		\
		ft_split.c		\
		sorting.c		\
		operations_1.c	\
		operations_2.c	\
		ft_lst.c		\
		structure.c




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
