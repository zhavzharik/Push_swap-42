/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:55:50 by abridger          #+#    #+#             */
/*   Updated: 2021/09/03 23:03:19 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_game(t_stack **a, t_stack **b, t_data *data)
{
	int		check;
	t_stack	*last;

	while (whether_sorted(*a, data) != 1 && (*a)->flag != 0)
	{
		last = ft_lstlast((*a));
		check = (*a)->flag;
		while ((*a)->flag == check && (*a)->flag != 0)
		{
			if ((*a)->indx == data->next && last->indx == data->next - 1) // check b
			{
				rotate(a, 1, data);
				data->next += 1;
			}
			else
				push(a, b, 2, data);
		}
		while (*b)  // выделить в отдельную функцию и добавить другой алгоритм при трех
		{
			update_mid(data);
			process_b(a, b, data);
		}
		while ((*a)->indx == data->next)
			update_next(a, b, data);
	}
}

void	update_max(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	data->max = data->size;
	data->mid = (data->max - data->next) / 2 + data->next;
	last = last_unsorted(*a);
	process_a(a, b, data, last);
	// start_game(a, b, data);
}
