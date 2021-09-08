/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:27:32 by abridger          #+#    #+#             */
/*   Updated: 2021/09/08 15:34:30 by abridger         ###   ########.fr       */
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
