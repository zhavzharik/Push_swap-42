/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oper_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:04:31 by abridger          #+#    #+#             */
/*   Updated: 2021/09/13 23:06:25 by abridger         ###   ########.fr       */
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
