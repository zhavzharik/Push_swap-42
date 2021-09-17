NAME = libft.a

LIST =			ft_atoi.c			\
				ft_isdigit.c		\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstlast.c		\
				ft_lstsize.c		\
				ft_putchar.c		\
				ft_puterror.c		\
				ft_putnbr.c			\
				ft_putstr.c			\
				ft_strcmp.c			\
				ft_strdup.c			\
				ft_strlen.c


OBJ = $(LIST:.c=.o)

CC = gcc

REM = rm -f

LIBH = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c $(LIBH)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(REM) $(OBJ)

fclean : clean
	$(REM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
