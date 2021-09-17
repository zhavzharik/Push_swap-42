/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:30:24 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 20:02:38 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int				*array;
	int				*sorted;
	int				size;
	int				flag;
	int				next;
	int				mid;
	int				max;
}					t_data;

int			get_index(t_data *data, int i);
void		from_array(t_stack **a, t_data *data);
int			check_first_ch(int c);
void		check_argv(int argc, char **argv);
void		check_duplicate(int argc, t_data *data);
int			get_min(t_data *data);
int			get_max(t_data *data);
int			next_min(t_data *data, int min);
void		sorting_arr(t_data *data);
void		rotate(t_stack **curr, int flag);
void		swap(t_stack **curr, int flag);
t_stack		*ft_lstlastbutone(t_stack *lst);
void		rev_rotate(t_stack **curr, int flag);
void		swap_two(t_stack **a, t_stack **b, int flag);
void		push(t_stack **from, t_stack **where, int flag);
void		rotate_two(t_stack **a, t_stack **b, int flag);
void		rev_rotate_two(t_stack **a, t_stack **b, int flag);
t_data		*init_struct(int argc, char **argv);
void		process_a(t_stack **a, t_stack **b, t_data *data, t_stack *last);
void		update_mid(t_data *data, t_stack **b);
void		process_b(t_stack **a, t_stack **b, t_data *data);
void		process_btail(t_stack **a, t_stack **b, t_data *data);
void		update_next(t_stack **a, t_stack **b, t_data *data);
void		ft_structclear(t_data *data);
void		ft_allclear(t_stack **a, t_stack **b, t_data *data);
void		start_game(t_stack **a, t_stack **b, t_data *data, t_stack *last);
int			whether_sorted(const t_stack *a, t_data *data);
void		process_game(t_stack **a, t_stack **b, t_data *data);
void		update_max(t_data *data);
void		process_unsorted(t_stack **a, t_stack **b, t_data *data);
t_stack		*lastbutone_unsorted(t_stack *lst);
void		game(t_stack **a, t_stack **b, t_data *data);
void		stack_two(t_stack **a);
void		stack_three(t_stack **curr, int flag);
void		stack_four(t_stack **a, t_stack **b, t_data *data);
void		stack_five(t_stack **a, t_stack **b, t_data *data);
void		short_stack(t_stack **a, t_stack **b, t_data *data);
void		check_topa(t_stack **a, t_stack **b, t_data *data);
void		rotate_cond(t_stack **a, t_stack **b, t_data *data);
void		sort_b(t_stack **a, t_stack **b, t_data *data);
void		check_topalast(t_stack **a, t_stack **b, t_data *data);
void		first_step_100(t_stack **a, t_stack **b);
void		second_step_100(t_stack **a, t_stack **b);
void		stack_100(t_stack **a, t_stack **b, t_data *data);

#endif
