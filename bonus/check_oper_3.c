/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oper_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:02:39 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:16:58 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	rev_rotate_r(t_stack **a, t_stack **b)
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
	}
}
