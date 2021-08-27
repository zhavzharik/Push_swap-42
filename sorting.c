/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:02:32 by abridger          #+#    #+#             */
/*   Updated: 2021/08/27 20:48:43 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int *array, int size)
{
	int	min;
	int	i;

	min = array[0];
	i = 1;
	while (i < size)
	{
		if (min > array[i])
			min = array[i];
		i++;
	}
	return (min);
}

int	get_max(int *array, int size)
{
	int	max;
	int	i;

	max = array[0];
	i = 1;
	while (i < size)
	{
		if (max < array[i])
			max = array[i];
		i++;
	}
	return (max);
}

int	next_min(int *array, int min, int size)
{
	int	n_min;
	int	i;

	n_min = get_max(array, size);
	i = 0;
	while (i < size)
	{
		if (n_min > array[i] && min < array[i])
			n_min = array[i];
		i++;
	}
	return (n_min);
}

int	*sorting_arr(int *array, int size)
{
	int	*sorted;
	int	i;
	int	min;
	int	n_min;

	sorted = (int *)malloc(sizeof(int) * size);
	min = get_min(array, size);
	sorted[0] = min;
	i = 1;
	while (i < size)
	{
		n_min = next_min(array, min, size);
		sorted[i] = n_min;
		min = n_min;
		i++;
	}
	return (sorted);
}
