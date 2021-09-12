/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oper_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:55:59 by abridger          #+#    #+#             */
/*   Updated: 2021/09/12 20:44:39 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	swap_two(a, b, 4);
}

void	push_a(t_stack **a, t_stack **b)
{
	push(b, a, 4);
}

void	push_b(t_stack **a, t_stack **b)
{
	push(a, b, 4);
}
