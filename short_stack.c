/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:39:57 by abridger          #+#    #+#             */
/*   Updated: 2021/09/04 22:49:12 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_two(t_stack **a, t_data *data)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 2)
	{
		if ((*a)->nb > (*a)->next->nb)
			swap(a, 1, data);
	}
}

void	stack_three(t_stack **curr, int flag, t_data *data)
{
	int	len;

	len = ft_lstsize(*curr);
	if (len == 3)
	{
		if ((*curr)->nb > (*curr)->next->nb
			&& (*curr)->nb > (*curr)->next->next->nb)
		{
			rotate(curr, flag, data);
			if ((*curr)->nb > (*curr)->next->nb)
				swap(curr, flag, data);
		}
		else if ((*curr)->nb > (*curr)->next->nb
			&& (*curr)->nb < (*curr)->next->next->nb)
			swap(curr, flag, data);
		else if ((*curr)->nb < (*curr)->next->nb
			&& (*curr)->next->nb > (*curr)->next->next->nb)
		{
			rev_rotate(curr, flag, data);
			if ((*curr)->nb > (*curr)->next->nb)
				swap(curr, flag, data);
		}
	}
}

void	stack_four(t_stack **a, t_stack **b, t_data *data)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 4)
	{
		if ((*a)->indx == 1 || (*a)->next->indx == 1)
		{
			if ((*a)->next->indx == 1)
				swap(a, 1, data);
			push(a, b, 2, data);
		}
		else
		{
			rev_rotate(a, 1, data);
			if ((*a)->indx == 1)
				push(a, b, 2, data);
			else
			{
				rev_rotate(a, 1, data);
				if ((*a)->indx == 1)
					push(a, b, 2, data);
			}
		}
		// stack_three(a, 1, data);
		// push(b, a, 1, data);
	}
}

void	short_stack(t_stack **a, t_stack **b, t_data *data)
{
	stack_two(a, data);
	stack_four(a, b, data);
	stack_three(a, 1, data);
	if (*b)
		push(b, a, 1, data);
	testing(*a, *b, data); // delete
}
