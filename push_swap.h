/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:30:24 by abridger          #+#    #+#             */
/*   Updated: 2021/08/05 22:18:03 by abridger         ###   ########.fr       */
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
void	ft_lstadd_front(t_stack **a, int number, int index);
size_t	get_index(int *array, int *sorted, size_t size);
void	from_array(t_stack **a, int *array, int *sorted, size_t size);
void	ft_print_stack(const t_stack *a); // переписать функцию
void	ft_print_order(const t_stack *a); // для проверки, потом удалить функцию

#endif
