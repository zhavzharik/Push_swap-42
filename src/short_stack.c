/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:39:57 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:13:11 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_two(t_stack **a)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 2)
	{
		if ((*a)->nb > (*a)->next->nb)
			swap(a, 1);
	}
}

void	stack_three(t_stack **curr, int flag)
{
	int	len;

	len = ft_lstsize(*curr);
	if (len == 3)
	{
		if ((*curr)->nb > (*curr)->next->nb
			&& (*curr)->nb > (*curr)->next->next->nb)
		{
			rotate(curr, flag);
			if ((*curr)->nb > (*curr)->next->nb)
				swap(curr, flag);
		}
		else if ((*curr)->nb > (*curr)->next->nb
			&& (*curr)->nb < (*curr)->next->next->nb)
			swap(curr, flag);
		else if ((*curr)->nb < (*curr)->next->nb
			&& (*curr)->next->nb > (*curr)->next->next->nb)
		{
			rev_rotate(curr, flag);
			if ((*curr)->nb > (*curr)->next->nb)
				swap(curr, flag);
		}
	}
}

void	stack_four(t_stack **a, t_stack **b, t_data *data)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 4)
	{
		if ((*a)->indx == data->next || (*a)->next->indx == data->next)
		{
			if ((*a)->next->indx == data->next)
				swap(a, 1);
		}
		else
		{
			while ((*a)->indx != data->next)
				rev_rotate(a, 1);
		}
		if ((*a)->indx == data->next)
		{
			push(a, b, 2);
			data->next += 1;
		}
	}
}

void	stack_five(t_stack **a, t_stack **b, t_data *data)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 5)
	{
		if ((*a)->indx == data->next || (*a)->next->indx == data->next
			|| (*a)->next->next->indx == data->next)
		{
			if ((*a)->next->indx == data->next)
				swap(a, 1);
			else if ((*a)->next->next->indx == data->next)
				while ((*a)->indx != data->next)
					rotate(a, 1);
		}
		else
		{
			while ((*a)->indx != data->next)
				rev_rotate(a, 1);
		}
		if ((*a)->indx == data->next)
		{
			push(a, b, 2);
			data->next += 1;
		}
	}
}

void	short_stack(t_stack **a, t_stack **b, t_data *data)
{
	stack_two(a);
	stack_five(a, b, data);
	stack_four(a, b, data);
	stack_three(a, 1);
	while (*b)
		push(b, a, 1);
}
