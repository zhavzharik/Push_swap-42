/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:27:32 by abridger          #+#    #+#             */
/*   Updated: 2021/08/14 16:51:06 by abridger         ###   ########.fr       */
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

int	get_index(int number, int *sorted, int size)
{
	int	j;
	int	indx;

	j = size - 1;
	while (j-- > 0)
	{
		if (number == sorted[j])
			indx = j + 1;
	}
	return (indx);
}

void	from_array(t_stack **a, int *array, int *sorted, int size)
{
	int	i;
	int	j;

	i = size - 1;
	if (array == NULL || size == 0)
		ft_puterror();
	while (i-- > 0)
	{
		j = get_index(array[i], sorted, size);
		ft_lstadd_front(a, array[i], j);
	}
}

void	ft_print_stack(const t_stack *a)
{
	while (a)
	{
		ft_putnbr(a->nb);
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
