/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:46:08 by abridger          #+#    #+#             */
/*   Updated: 2021/08/30 22:28:42 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_a(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	last = ft_lstlast((*a));
	while ((*a)->next != last->next)
	{
		if ((*a)->indx <= data->mid)
			push(a, b, 2);
		else
			rotate(a, 1);
	}
	if ((*a)->indx <= data->mid)
		push(a, b, 2);
	else
		rotate(a, 1);
}

void	update_mid(t_data *data)
{
	data->max = data->mid;
	data->mid = (data->max - data->next) / 2 + data->next;
	data->flag += 1;
}

void	process_b(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	last = ft_lstlast((*b));
	while ((*b)->next != last->next)
	{
		if ((*b)->indx >= data->mid || (*b)->indx == data->next)
		{
			(*b)->flag = data->flag;
			push(b, a, 1);
			update_next(a, b, data);
		}
		else
			rotate(b, 2);
	}
	if ((*b)->indx >= data->mid)
	{
		(*b)->flag = data->flag;
		push(b, a, 1);
		update_next(a, b, data);
	}
	else
		rotate(b, 2);
}

void	update_next(t_stack **a, t_stack **b, t_data *data)
{
	if ((*a)->indx == data->next && (*b)->indx < data->mid)
	{
		rotate_two(a, b);
		data->next += 1;
	}
	else if ((*a)->indx == data->next && (*b)->indx >= data->mid)
	{
		rotate(a, 1);
		data->next += 1;
	}
}
