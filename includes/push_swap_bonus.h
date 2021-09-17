/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:30:24 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 20:03:13 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
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

typedef void	(*t_action)(t_stack **, t_stack **);
enum	e_instr {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

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
void		ft_structclear(t_data *data);
void		ft_allclear(t_stack **a, t_stack **b, t_data *data);
int			whether_sorted(const t_stack *a, t_data *data);
int			reading_instr(int rd, char **line);
char		**create_array_instr(void);
t_action	*create_array_function(void);
void		get_execute(t_stack **a, t_stack **b);
void		swap_a(t_stack **a, t_stack **b);
void		swap_b(t_stack **a, t_stack **b);
void		swap_s(t_stack **a, t_stack **b);
void		push_a(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);
void		rotate_a(t_stack **a, t_stack **b);
void		rotate_b(t_stack **a, t_stack **b);
void		rotate_r(t_stack **a, t_stack **b);
void		rev_rotate_a(t_stack **a, t_stack **b);
void		rev_rotate_b(t_stack **a, t_stack **b);
void		rev_rotate_r(t_stack **a, t_stack **b);
void		ft_array_clear(char **instr, t_action *func);
int			max_index(t_stack *curr);
int			check_position(t_stack *curr);

#endif
