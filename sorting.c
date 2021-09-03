/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:02:32 by abridger          #+#    #+#             */
/*   Updated: 2021/09/03 16:58:48 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_data *data)
{
	int	min;
	int	i;

	min = data->array[0];
	i = 1;
	while (i < data->size)
	{
		if (min > data->array[i])
			min = data->array[i];
		i++;
	}
	return (min);
}

int	get_max(t_data *data)
{
	int	max;
	int	i;

	max = data->array[0];
	i = 1;
	while (i < data->size)
	{
		if (max < data->array[i])
			max = data->array[i];
		i++;
	}
	return (max);
}

int	next_min(t_data *data, int min)
{
	int	n_min;
	int	i;

	n_min = get_max(data);
	i = 0;
	while (i < data->size)
	{
		if (n_min > data->array[i] && min < data->array[i])
			n_min = data->array[i];
		i++;
	}
	return (n_min);
}

void	sorting_arr(t_data *data)
{
	int	i;
	int	min;
	int	n_min;

	data->sorted = (int *)malloc(sizeof(int) * data->size);
	min = get_min(data);
	data->sorted[0] = min;
	i = 1;
	while (i < data->size)
	{
		n_min = next_min(data, min);
		data->sorted[i] = n_min;
		min = n_min;
		i++;
	}
}

int	whether_sorted(const t_stack *a, t_data *data)
{
	int	i;
	int	value;

	i = 0;
	value = 2;
	if (a && data)
	{
		while (a && value > 0)
		{
			if (a->nb == data->sorted[i])
				value = 1;
			else
				value = 0;
			a = a->next;
			i++;
		}
	}
	return (value);
}
