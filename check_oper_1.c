/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oper_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:55:59 by abridger          #+#    #+#             */
/*   Updated: 2021/09/09 22:02:26 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_check(t_stack **curr)
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
	}
}

void	swap_check(t_stack **curr)
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
	}
}

void	rev_rotatecheck(t_stack **curr)
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
	}
}

void	push_check(t_stack **from, t_stack **where)
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
	}
}
