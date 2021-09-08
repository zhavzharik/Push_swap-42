/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:33:48 by abridger          #+#    #+#             */
/*   Updated: 2021/09/08 18:19:59 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(const t_stack *a, t_data *data)
{
	if (a)
	{
		ft_putstr("Number\t");
		ft_putstr("Order\t");
		ft_putstr("Flag\t");
		ft_putstr("Max\t");
		ft_putstr("Mid\t");
		ft_putstr("Next\n");
	}
	while (a)
	{
		ft_putnbr(a->nb);
		ft_putchar('\t');
		ft_putnbr(a->indx);
		ft_putchar('\t');
		ft_putnbr(a->flag);
		ft_putchar('\t');
		ft_putnbr(data->max);
		ft_putchar('\t');
		ft_putnbr(data->mid);
		ft_putchar('\t');
		ft_putnbr(data->next);
		ft_putchar('\n');
		a = a->next;
	}
}

void	testing(t_stack *a, t_stack *b, t_data *data)
{
	printf("MID = %d\n", data->mid);
	printf("Index = %d\n", (a)->indx);
	printf("Number = %d\n", (a)->nb);
	printf("NEXT = %d\n", data->next);
	printf("Стек А:\n");
	ft_print_stack(a, data);
	printf("Стек B:\n");
	ft_print_stack(b, data);
}

void	ft_print_order(const t_stack *a) // для проверки, потом удалить функцию
{
	while (a)
	{
		ft_putnbr(a->indx);
		ft_putchar('\n');
		a = a->next;
	}
}
