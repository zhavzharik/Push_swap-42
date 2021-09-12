/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:06:37 by abridger          #+#    #+#             */
/*   Updated: 2021/09/12 18:43:23 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stack **a, t_stack **b, t_data *data)
{
	while (*b)
	{
		update_mid(data, b);
		process_b(a, b, data);
	}
}

void	check_topalast(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	while ((*a)->indx == data->next || (*a)->next->indx == data->next)
	{
		last = ft_lstlast(*a);
		if ((*a)->next->indx == data->next && last->indx == data->next - 1)
			swap(a, 1); //, data);
		update_next(a, b, data);
	}
}

void	process_btail(t_stack **a, t_stack **b, t_data *data)
{
	if ((*b)->indx >= data->mid || (*b)->indx == data->next)
	{
		check_topa(a, b, data);
		(*b)->flag = data->flag;
		push(b, a, 1); //, data);
		update_next(a, b, data);
		check_topa(a, b, data);
	}
}
