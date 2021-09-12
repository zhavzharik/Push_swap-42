# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 20:22:10 by abridger          #+#    #+#              #
#    Updated: 2021/09/12 20:34:17 by abridger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

SRC_PS = 	push_swap.c		\
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

SRC_CH =	checker.c		\
			ft_atoi.c		\
			structure.c		\
			sorting.c		\
			parser.c		\
			check_argv.c	\
			ft_str.c		\
			operations_1.c	\
			operations_2.c	\
			check_oper_1.c	\
			check_oper_2.c	\
			check_oper_3.c	\
			ft_lst.c		\
			clear.c			\
			ft_strdup.c		\
			ft_strcmp.c		\
			read_exec.c


OBJ_PS = $(SRC_PS:.c=.o)

OBJ_CH = $(SRC_CH:.c=.o)

CC = gcc

REM = rm -f

INCL = push_swap.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(CHECKER)

%.o : %.c $(INCL) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_PS)
	$(CC) $(FLAGS) $(OBJ_PS) -o $(NAME)

$(CHECKER): $(OBJ_CH)
	$(CC) $(FLAGS) $(OBJ_CH) -o $(CHECKER)

clean :
	$(REM) $(OBJ_PS) $(OBJ_CH)

fclean : clean
	$(REM) $(NAME) $(CHECKER)

re : fclean all

.PHONY : all clean fclean re
