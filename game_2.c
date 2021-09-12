/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:55:50 by abridger          #+#    #+#             */
/*   Updated: 2021/09/12 20:27:06 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_game(t_stack **a, t_stack **b, t_data *data)
{
	int		check;
	t_stack	*last;

	while (whether_sorted(*a, data) != 1 && (*a)->flag != 0)
	{
		check = (*a)->flag;
		while ((*a)->flag == check && (*a)->flag != 0)
		{
			last = ft_lstlast(*a);
			if ((*a)->indx == data->next && last->indx == data->next - 1)
			{
				rotate(a, 1); //, data);
				data->next += 1;
			}
			else
				push(a, b, 2); //, data);
		}
		sort_b(a, b, data);
		check_topalast(a, b, data);
	}
}

void	update_max(t_data *data)
{
	if (data)
	{
		data->max = data->size;
		data->mid = (data->max - data->next) / 2 + data->next;
	}
}

void	process_unsorted(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*unsorted;

	if (whether_sorted(*a, data) != 1)
	{
		update_max(data);
		unsorted = lastbutone_unsorted(*a);
		process_a(a, b, data, unsorted);
		update_mid(data, b);
		while (ft_lstlast(*a)->flag == 0 && (*b)->indx != data->next)
			rev_rotate_two(a, b, 3); //, data);
		while (ft_lstlast(*a)->flag == 0
			&& ft_lstlast(*a)->indx != data->next - 1
			&& ft_lstlastbutone(*a)->indx != data->next - 2)
			rev_rotate(a, 1); //, data);
		while (*b)
		{
			process_b(a, b, data);
			update_mid(data, b);
		}
		check_topa(a, b, data);
	}
}

void	game(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	last = ft_lstlast(*a);
	start_game(a, b, data, last);
	while (whether_sorted(*a, data) != 1)
	{
		process_game(a, b, data);
		update_max(data);
		process_unsorted(a, b, data);
	}
}

void	check_topa(t_stack **a, t_stack **b, t_data *data)
{
	while ((*a)->indx == data->next || (*a)->next->indx == data->next)
	{
		if ((*a)->next->indx == data->next)
			swap(a, 1); //, data);
		update_next(a, b, data);
	}
}
