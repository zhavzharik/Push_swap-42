/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:02:32 by abridger          #+#    #+#             */
/*   Updated: 2021/08/28 16:31:59 by abridger         ###   ########.fr       */
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

void	sorting_arr(t_data *data, int argc)
{
	int	i;
	int	min;
	int	n_min;

	data->size = argc - 1;
	data->sorted = (int *)malloc(sizeof(int) * data->size);
	min = get_min(data);
	data->sorted[0] = min;
	i = 1;
	while (i < data->size)
	{
		n_min = next_min(data, min);
		sorted[i] = n_min;
		min = n_min;
		i++;
	}
}
