/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:27:32 by abridger          #+#    #+#             */
/*   Updated: 2021/09/03 21:02:44 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **a, int number, int index)
{
	t_stack	*tmp;

	tmp = (t_stack *) malloc(sizeof(t_stack));
	if (!tmp)
		ft_puterror();
	tmp->nb = number;
	tmp->indx = index;
	tmp->flag = 0;
	tmp->next = (*a);
	(*a) = tmp;
}

int	get_index(t_data *data, int i)
{
	int	j;
	int	indx;

	j = data->size - 1;
	while (j >= 0)
	{
		if (data->array[i] == data->sorted[j])
			indx = j + 1;
		j--;
	}
	return (indx);
}

void	from_array(t_stack **a, t_data *data)
{
	int	i;
	int	j;

	i = data->size - 1;
	if (data->array == NULL || data->size == 0)
		ft_puterror();
	while (i >= 0)
	{
		j = get_index(data, i);
		ft_lstadd_front(a, data->array[i], j);
		i--;
	}
}

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

void	ft_print_order(const t_stack *a) // для проверки, потом удалить функцию
{
	while (a)
	{
		ft_putnbr(a->indx);
		ft_putchar('\n');
		a = a->next;
	}
}
