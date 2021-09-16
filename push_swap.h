/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:30:24 by abridger          #+#    #+#             */
/*   Updated: 2021/09/16 19:51:45 by abridger         ###   ########.fr       */
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
	struct s_stack	*next;
}					t_stack;

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

void		ft_puterror(void);
int			ft_atoi(const char *str);
void		ft_putchar(char c);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
void		ft_putnbr(int n);
void		ft_lstadd_front(t_stack **a, int number, int index);
int			get_index(t_data *data, int i);
void		from_array(t_stack **a, t_data *data);
int			ft_isdigit(int c);
int			ft_isfirst(int c);
void		check_argv(int argc, char **argv);
void		check_duplicate(int argc, t_data *data);
int			get_min(t_data *data);
int			get_max(t_data *data);
int			next_min(t_data *data, int min);
void		sorting_arr(t_data *data);
t_stack		*ft_lstlast(t_stack *lst);
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
void		ft_lstclear(t_stack **lst);
void		ft_structclear(t_data *data);
void		ft_allclear(t_stack **a, t_stack **b, t_data *data);
void		start_game(t_stack **a, t_stack **b, t_data *data, t_stack *last);
int			whether_sorted(const t_stack *a, t_data *data);
void		process_game(t_stack **a, t_stack **b, t_data *data);
void		update_max(t_data *data);
void		process_unsorted(t_stack **a, t_stack **b, t_data *data);
t_stack		*lastbutone_unsorted(t_stack *lst);
int			ft_lstsize(t_stack *lst);
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
char		*ft_strdup(char *s1); // add libft folder and change Makefile
int			ft_strcmp(const char *s1, const char *s2);
int			reading_instr(int rd, char **line); // for bonus
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
