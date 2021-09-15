/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:29:06 by abridger          #+#    #+#             */
/*   Updated: 2021/09/15 20:34:26 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;

	if (argc == 1)
		exit (0);
	a = NULL;
	data = init_struct(argc, argv);
	if (!data)
		exit (0);
	sorting_arr(data);
	from_array(&a, data);
	b = NULL;
	if (whether_sorted(a, data) == 1)
		exit (0);
	printf("Количество чисел [%d]\n", data->size); // delete
	if (data->size < 6)
		short_stack(&a, &b, data);
	else if (data->size < 102)
	{
		printf("Стек от 6 до 101:\n"); // delete
		stack_100(&a, &b, data);
	}
	else
		game(&a, &b, data);
	ft_allclear(&a, &b, data);
	return (0);
}
