/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:55:23 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:13:18 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_index(t_stack *curr)
{
	int	max_index;

	max_index = 1;
	if (curr)
	{
		max_index = curr->indx;
		while (curr != NULL)
		{
			if (max_index < curr->indx)
				max_index = curr->indx;
			curr = curr->next;
		}
	}
	return (max_index);
}

int	check_position(t_stack *curr)
{
	int	len;
	int	pos;
	int	check;

	pos = 1;
	if (!curr)
		return (0);
	len = ft_lstsize(curr);
	check = max_index(curr);
	while (curr->next && curr->indx != check)
	{
		pos++;
		curr = curr->next;
	}
	if (pos > len / 2)
		check = 1;
	else
		check = 0;
	return (check);
}

void	first_step_100(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while ((*a) != NULL)
	{
		if (i > 1 && (*a)->indx <= i)
		{
			push(a, b, 2);
			rotate(b, 2);
			i++;
		}
		else if ((*a)->indx <= i + 15)
		{
			push(a, b, 2);
			i++;
		}
		else if ((*a)->indx >= i && ft_lstsize(*a) > 1)
		{
			rotate(a, 1);
		}
	}
}

void	second_step_100(t_stack **a, t_stack **b)
{
	int	check;

	while ((*b) != NULL)
	{
		check = max_index(*b);
		if ((*b)->indx != check && !check_position(*b))
		{
			while ((*b)->indx != check)
				rotate(b, 2);
			push(b, a, 1);
		}
		else if ((*b)->indx != check && check_position(*b))
		{
			while ((*b)->indx != check)
				rev_rotate(b, 2);
			push(b, a, 1);
		}
		else if ((*b)->indx == check)
			push(b, a, 1);
	}
}

void	stack_100(t_stack **a, t_stack **b, t_data *data)
{
	if (whether_sorted(*a, data) != 1)
	{
		first_step_100(a, b);
		second_step_100(a, b);
	}
}
