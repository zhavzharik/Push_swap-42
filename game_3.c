/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:06:37 by abridger          #+#    #+#             */
/*   Updated: 2021/09/07 19:38:51 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_topb(t_stack **a, t_stack **b, t_data *data)
{
	// if ((*b) && (*b)->next)
	// {
	// 	while ((*b && (*b)->indx == data->next) || ((*b)->next && (*b)->next->indx == data->next))
	// 	{
	// 		if ((*b)->next->indx == data->next)
	// 			swap(b, 2, data);
	// 		// push(b, a, 1, data);
	// 		// update_next(a, b, data);
	// 	}
	// }
	if (*b)
	{
		while ((*b) && (*b)->indx == data->next)
		{
			(*b)->flag = data->flag;
			push(b, a, 1, data);
			update_next(a, b, data);
		}
	}
}
