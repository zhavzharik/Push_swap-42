/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:30:24 by abridger          #+#    #+#             */
/*   Updated: 2021/08/28 14:33:50 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h> // для принтф, потом удалить

typedef struct s_stack
{
	int				nb;
	int				indx;
	int				flag;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data // пока не используется
{
	// int				*input;
	// int				*sorted;
	int				next;
	int				mid;
	int				max;
	// int				len_a;
	// int				len_b;
	// char			*action;
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
void	check_string(int argc, char **argv);
size_t	ft_words_nb(char const *s, char c);
int		*ft_split(char const *s, char c);
void	check_duplicate(int argc, int *array);
int		get_min(int *array, int size);
int		get_max(int *array, int size);
int		next_min(int *array, int min, int size);
int		*sorting_arr(int *array, int size);
t_stack	*ft_lstlast(t_stack *lst);
void	rotate(t_stack **curr, int flag);
void	testing(t_stack *a, t_stack *b); // delete
void	swap(t_stack **curr, int flag);
t_stack	*ft_lstlastbutone(t_stack *lst);
void	rev_rotate(t_stack **curr, int flag);
void	push(t_stack **from, t_stack **where, int flag);
t_stack	*ft_lstinit(void);
void	rotate_two(t_stack **a, t_stack **b);
void	rev_rotate_two(t_stack **a, t_stack **b);

#endif
