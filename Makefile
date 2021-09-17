# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 20:22:10 by abridger          #+#    #+#              #
#    Updated: 2021/09/17 20:44:05 by abridger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap

NAME_CH = checker

SRC_PS = 	./src/push_swap.c				\
			./src/check_argv.c				\
			./src/parser.c					\
			./src/sorting_array.c			\
			./src/operations_1.c			\
			./src/operations_2.c			\
			./src/lst_utils.c				\
			./src/structure.c				\
			./src/game_1.c					\
			./src/clear.c					\
			./src/game_2.c					\
			./src/short_stack.c				\
			./src/game_3.c					\
			./src/sorting_100.c


SRC_CH =	./bonus/checker.c				\
			./bonus/check_oper_1.c			\
			./bonus/check_oper_2.c			\
			./bonus/check_oper_3.c			\
			./bonus/read_exec.c				\
			./bonus/structure_bonus.c		\
			./bonus/sorting_array_bonus.c	\
			./bonus/parser_bonus.c			\
			./bonus/check_argv_bonus.c		\
			./bonus/operations_1_bonus.c	\
			./bonus/operations_2_bonus.c	\
			./bonus/lst_utils_bonus.c		\
			./bonus/clear_bonus.c

LIBFT_DIR	=	./libft/

OBJ_PS = $(SRC_PS:.c=.o)

OBJ_CH = $(SRC_CH:.c=.o)

CC = gcc

REM = rm -f

INCL = ./includes/push_swap.h

INCL_B = ./includes/push_swap_bonus.h

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

FLAGS = -Wall -Wextra -Werror

all: $(NAME_PS)

%.o : %.c $(INCL) $(INCL_B) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME_PS): $(OBJ_PS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_PS) $(LIBFT) -o $(NAME_PS)

$(NAME_CH): $(OBJ_CH) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_CH) $(LIBFT) -o $(NAME_CH)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(NAME_CH)

clean :
	$(REM) $(OBJ_PS) $(OBJ_CH)
	make clean -C $(LIBFT_DIR) fclean

fclean : clean
	$(REM) $(NAME_PS) $(NAME_CH)
	make clean -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
