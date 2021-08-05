/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:27:32 by abridger          #+#    #+#             */
/*   Updated: 2021/08/05 22:42:18 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // потом удалить, длбавила для принтф

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

size_t	get_index(int *array, int *sorted, size_t size)
{
	size_t	i;
	size_t	j;

	i = size - 1;
	while (i != 0)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] == sorted[j])
				return (j + 1);
			else
				j++;
		}
		i--;
	}
	return (0); // подумать, переписать
}

void	from_array(t_stack **a, int *array, int *sorted, size_t size)
{
	size_t	i;
	size_t	j;

	i = size - 1;
	if (array == NULL || size == 0)
		ft_puterror();
	while (i-- > 0)
	{
		j = get_index(array, sorted, size); // неверно определяется индекс
		ft_lstadd_front(a, array[i], j);
	}
}

void	ft_print_stack(const t_stack *a)
{
	while (a)
	{
		printf("%d\n", a->nb); // переписать на самописный принтф
		a = a->next;
	}
}

void	ft_print_order(const t_stack *a) // для проверки, потом удалить функцию
{
	while (a)
	{
		printf("%d\n", a->indx); // переписать на самописный принтф
		a = a->next;
	}
}
