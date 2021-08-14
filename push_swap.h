/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:30:24 by abridger          #+#    #+#             */
/*   Updated: 2021/08/14 22:19:24 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	int				indx;
	int				flag;
	//struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data // пока не используется
{
	int				*input;
	int				*sorted;
	int				next;
	int				len_a;
	int				len_b;
	char			*action;
}					t_data;

void	ft_puterror(void);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_lstadd_front(t_stack **a, int number, int index);
int		get_index(int number, int *sorted, int size);
void	from_array(t_stack **a, int *array, int *sorted, int size);
void	ft_print_stack(const t_stack *a);
void	ft_print_order(const t_stack *a); // для проверки, потом удалить функцию
int		ft_isalpha(int c);
void	check_argv(int argc, char **argv);

#endif
