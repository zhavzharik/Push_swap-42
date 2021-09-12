/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oper_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:04:31 by abridger          #+#    #+#             */
/*   Updated: 2021/09/12 20:03:12 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	rotate_two(a, b, 4);
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
// void	rotate_twocheck(t_stack **a, t_stack **b)
// {
// 	t_stack	*tmp_a;
// 	t_stack	*last_a;
// 	t_stack	*tmp_b;
// 	t_stack	*last_b;

// 	if ((*a) && (*a)->next && (*b) && (*b)->next)
// 	{
// 		last_a = ft_lstlast(*a);
// 		tmp_a = (*a)->next;
// 		last_a->next = (*a);
// 		(*a)->next = NULL;
// 		(*a) = tmp_a;
// 		last_b = ft_lstlast(*b);
// 		tmp_b = (*b)->next;
// 		last_b->next = (*b);
// 		(*b)->next = NULL;
// 		(*b) = tmp_b;
// 	}
// }

// void	rev_rotate_twocheck(t_stack **a, t_stack **b)
// {
// 	t_stack	*tmp_a;
// 	t_stack	*last_a;
// 	t_stack	*tmp_b;
// 	t_stack	*last_b;

// 	if ((*a) && (*a)->next && (*b) && (*b)->next)
// 	{
// 		last_a = ft_lstlast(*a);
// 		tmp_a = ft_lstlastbutone(*a);
// 		last_a->next = (*a);
// 		tmp_a->next = NULL;
// 		(*a) = last_a;
// 		last_b = ft_lstlast(*b);
// 		tmp_b = ft_lstlastbutone(*b);
// 		last_b->next = (*b);
// 		tmp_b->next = NULL;
// 		(*b) = last_b;
// 	}
// }

// void	swap_twocheck(t_stack **a, t_stack **b)
// {
// 	t_stack	*tmp_a;
// 	t_stack	*tmp_b;

// 	if ((*a) && (*a)->next && (*b) && (*b)->next)
// 	{
// 		tmp_a = (*a)->next;
// 		if ((*a)->next->next)
// 			(*a)->next = (*a)->next->next;
// 		else
// 			(*a)->next = NULL;
// 		tmp_a->next = (*a);
// 		(*a) = tmp_a;
// 		tmp_b = (*b)->next;
// 		if ((*b)->next->next)
// 			(*b)->next = (*b)->next->next;
// 		else
// 			(*b)->next = NULL;
// 		tmp_b->next = (*b);
// 		(*b) = tmp_b;
// 	}
// }
