/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oper_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:04:31 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:16:52 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	rotate_a(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a, 4);
}

void	rotate_b(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b, 4);
}

void	rotate_r(t_stack **a, t_stack **b)
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
	}
}

void	rev_rotate_a(t_stack **a, t_stack **b)
{
	(void)b;
	rev_rotate(a, 4);
}

void	rev_rotate_b(t_stack **a, t_stack **b)
{
	(void)a;
	rev_rotate(b, 4);
}
