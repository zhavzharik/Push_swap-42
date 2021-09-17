/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oper_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:55:59 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:16:44 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap_a(t_stack **a, t_stack **b)
{
	(void)b;
	swap(a, 4);
}

void	swap_b(t_stack **a, t_stack **b)
{
	(void)a;
	swap(b, 4);
}

void	swap_s(t_stack **a, t_stack **b)
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
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	push(b, a, 4);
}

void	push_b(t_stack **a, t_stack **b)
{
	push(a, b, 4);
}
