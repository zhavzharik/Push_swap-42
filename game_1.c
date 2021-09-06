/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:46:08 by abridger          #+#    #+#             */
/*   Updated: 2021/09/06 22:49:36 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_a(t_stack **a, t_stack **b, t_data *data, t_stack *last)
{
	while ((*a)->next != last->next)
	{
		if ((*a)->indx <= data->mid)
			push(a, b, 2, data);
		else
			rotate(a, 1, data);
	}
	if ((*a)->indx <= data->mid)
		push(a, b, 2, data);
	else
		rotate(a, 1, data);
}

void	update_mid(t_data *data)
{
	if (data)
	{
		data->max = data->mid;
		data->mid = (data->max - data->next) / 2 + data->next;
		data->flag += 1;
	}
}

void	process_b(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;
	t_stack	*lastbutone;

	last = ft_lstlast((*b));
	lastbutone = ft_lstlastbutone((*b));
	while ((*b)->next != last->next)
	{
		if ((*b)->indx >= data->mid || (*b)->indx == data->next)
		{
			check_topa(a, b, data);
			(*b)->flag = data->flag;
			push(b, a, 1, data);
			update_next(a, b, data);
		}
		else if ((*b) != lastbutone || ((*b) == lastbutone && last->indx >= data->next))
			rotate(b, 2, data);
	}
	if ((*b))
	{
		if ((*b)->indx >= data->mid)
		{
			check_topa(a, b, data);
			(*b)->flag = data->flag;
			push(b, a, 1, data);
			update_next(a, b, data);
		}
		// else
		// 	rotate(b, 2, data);
	}
}

void	update_next(t_stack **a, t_stack **b, t_data *data)
{
	if ((!(*b) && (*a)->indx == data->next)
		|| ((*a)->indx == data->next && (*b)->indx >= data->mid))
	{
		rotate(a, 1, data);
		data->next += 1;
	}
	else if ((*a) && (*b) && (*a)->indx == data->next && (*b)->indx < data->mid) // sign
	{
		rotate_two(a, b, data);
		data->next += 1;
	}
}

void	start_game(t_stack **a, t_stack **b, t_data *data, t_stack *last)
{
	// int	len_b;

	while ((*a)->indx == data->next || (*a)->next->indx == data->next)
	{
		if ((*a)->next->indx == data->next)
			swap(a, 1, data);
		update_next(a, b, data);
		// check_topb(a, b, data);
	}
	process_a(a, b, data, last);
	while (*b) // выделить в отдельную функцию и добавить другой алгоритм при трех
	{
		update_mid(data);
		process_b(a, b, data);
		// len_b = ft_lstsize(*b);
		// if (len_b == 3 || len_b == 2)
		// {
		// 	stack_two(b, data);
		// 	stack_three(b, 2, data);
		// 	// while (*b)
		// 	// 	push(b, a, 1, data);
		// }
	}
	while ((*a)->indx == data->next || (*a)->next->indx == data->next)
	{
		if ((*a)->next->indx == data->next)
			swap(a, 1, data);
		update_next(a, b, data);
		// check_topb(a, b, data);
	}
}
