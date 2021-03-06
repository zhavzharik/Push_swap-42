/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:26:07 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:12:40 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **curr, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*curr) && (*curr)->next)
	{
		last = ft_lstlast(*curr);
		tmp = (*curr)->next;
		last->next = (*curr);
		(*curr)->next = NULL;
		(*curr) = tmp;
		if (flag == 1)
		{
			write(1, "ra\n", 3);
		}
		if (flag == 2)
		{
			write(1, "rb\n", 3);
		}
	}
}

void	swap(t_stack **curr, int flag)
{
	t_stack	*tmp;

	if ((*curr) && (*curr)->next)
	{
		tmp = (*curr)->next;
		if ((*curr)->next->next)
			(*curr)->next = (*curr)->next->next;
		else
			(*curr)->next = NULL;
		tmp->next = (*curr);
		(*curr) = tmp;
		if (flag == 1)
		{
			write(1, "sa\n", 3);
		}
		if (flag == 2)
		{
			write(1, "sb\n", 3);
		}
	}
}

void	rev_rotate(t_stack **curr, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*curr) && (*curr)->next)
	{
		last = ft_lstlast(*curr);
		tmp = ft_lstlastbutone(*curr);
		last->next = (*curr);
		tmp->next = NULL;
		(*curr) = last;
		if (flag == 1)
		{
			write(1, "rra\n", 4);
		}
		if (flag == 2)
		{
			write(1, "rrb\n", 4);
		}
	}
}

void	push(t_stack **from, t_stack **where, int flag)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*from)
	{
		if ((*from) && (*from)->next)
			tmp = (*from)->next;
		(*from)->next = (*where);
		(*where) = (*from);
		(*from) = tmp;
		if (flag == 1)
		{
			write(1, "pa\n", 3);
		}
		if (flag == 2)
		{
			write(1, "pb\n", 3);
		}
	}
}
