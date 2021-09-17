/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:55:57 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:17:54 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_data	*init_struct(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = NULL;
	if (argc > 1)
	{
		data = (t_data *)malloc(sizeof(t_data));
		i = 1;
		check_argv(argc, argv);
		data->array = (int *)malloc(sizeof(int) * (argc - 1));
		while (i < argc)
		{
			data->array[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		check_duplicate(argc, data);
		data->size = argc - 1;
		data->flag = 0;
		data->next = 1;
		data->mid = data->size / 2 + data->next;
		data->max = data->size;
	}
	return (data);
}
