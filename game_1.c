/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:46:08 by abridger          #+#    #+#             */
/*   Updated: 2021/09/08 22:11:52 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_a(t_stack **a, t_stack **b, t_data *data, t_stack *last)
{
	if (whether_sorted(*a, data) != 1)
	{
		while ((*a)->next != last->next)
		{
			if (((*a)->indx <= data->mid && (*a)->nb != data->next)
				|| ((*a)->indx <= data->mid && (*a)->nb == data->next
					&& last->indx != data->next - 1))
				push(a, b, 2, data);
			else if ((*a)->nb == data->next && last->indx == data->next - 1)
				update_next(a, b, data);
			else
				rotate_cond(a, b, data);
		}
		if (((*a)->indx <= data->mid && (*a)->nb != data->next)
			|| ((*a)->indx <= data->mid && (*a)->nb == data->next
				&& last->indx != data->next - 1))
			push(a, b, 2, data);
		else if ((*a)->nb == data->next && last->indx == data->next - 1)
			update_next(a, b, data);
		else
			rotate_cond(a, b, data);
	}
}

void	update_mid(t_data *data, t_stack **b)
{
	int	len;

	len = ft_lstsize(*b);
	if (data && data->next > data->mid)
	{
		data->max = data->next + len - 1;
		data->mid = (data->max - data->next) / 2 + data->next;
		data->flag += 1;
	}
	else
	{
		data->max = data->mid;
		data->mid = (data->max - data->next) / 2 + data->next;
		data->flag += 1;
	}
}

void	process_b(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	if ((whether_sorted(*a, data) != 1 && (*b))
		|| (whether_sorted(*a, data) == 1 && (*b)))
	{
		// printf("Start process B\n"); //delete
		// testing(*a, *b, data); // delete
		last = ft_lstlast((*b));
		// printf("Last number: %d\t", last->nb); // delete
		while ((*b)->next != last->next)
		{
			if ((*b)->indx >= data->mid || (*b)->indx == data->next)
			{
				check_topa(a, b, data);
				(*b)->flag = data->flag;
				push(b, a, 1, data);
				update_next(a, b, data);
			}
			else
				rotate(b, 2, data);
		}
		if ((*b)) // if не нужен? проверить еще раз
			process_btail(a, b, data);
	}
}

void	update_next(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	last = ft_lstlast(*a);
	if ((!(*b) && (*a)->indx == data->next && data->next == 1)
		|| (!(*b) && (*a)->indx == data->next && last->indx == data->next - 1)
		|| ((*a)->indx == data->next && (*b)->indx >= data->mid
			&& data->next == 1)
		|| ((*a)->indx == data->next && (*b)->indx >= data->mid
			&& last->indx == data->next - 1))
	{
		rotate(a, 1, data);
		data->next += 1;
	}
	else if (((*a) && (*b) && (*a)->indx == data->next && (*b)->indx < data->mid
			&& data->next == 1)
		|| ((*a) && (*b) && (*a)->indx == data->next && (*b)->indx < data->mid
			&& last->indx == data->next - 1))
	{
		rotate_two(a, b, data);
		data->next += 1;
	}
}

void	start_game(t_stack **a, t_stack **b, t_data *data, t_stack *last)
{
	process_a(a, b, data, last);
	sort_b(a, b, data);
	check_topa(a, b, data);
}
