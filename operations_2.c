/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:52:14 by abridger          #+#    #+#             */
/*   Updated: 2021/09/03 16:01:01 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_two(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*last_a;
	t_stack	*tmp_b;
	t_stack	*last_b;

	if ((*a) && (*a)->next && (*b) && (*b)->next)
	{
		last_a = ft_lstlast(*a);
		tmp_a = (*a)->next;
		last_a->next = (*a);
		(*a)->next = NULL;
		(*a) = tmp_a;
		last_b = ft_lstlast(*b);
		tmp_b = (*b)->next;
		last_b->next = (*b);
		(*b)->next = NULL;
		(*b) = tmp_b;
		write(1, "rr\n", 3);
		data->operations += 1;
	}
}

void	rev_rotate_two(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*last_a;
	t_stack	*tmp_b;
	t_stack	*last_b;

	if ((*a) && (*a)->next && (*b) && (*b)->next)
	{
		last_a = ft_lstlast(*a);
		tmp_a = ft_lstlastbutone(*a);
		last_a->next = (*a);
		tmp_a->next = NULL;
		(*a) = last_a;
		last_b = ft_lstlast(*b);
		tmp_b = ft_lstlastbutone(*b);
		last_b->next = (*b);
		tmp_b->next = NULL;
		(*b) = last_b;
		write(1, "rrr\n", 4);
		data->operations += 1;
	}
}

void	swap_two(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if ((*a) && (*a)->next && (*b) && (*b)->next)
	{
		tmp_a = (*a)->next;
		if ((*a)->next->next)
			(*a)->next = (*a)->next->next;
		else
			(*a)->next = NULL;
		tmp_a->next = (*a);
		(*a) = tmp_a;
		tmp_b = (*b)->next;
		if ((*b)->next->next)
			(*b)->next = (*b)->next->next;
		else
			(*b)->next = NULL;
		tmp_b->next = (*b);
		(*b) = tmp_b;
		write(1, "ss\n", 3);
		data->operations += 1;
	}
}
