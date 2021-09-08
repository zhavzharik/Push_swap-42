/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:29:06 by abridger          #+#    #+#             */
/*   Updated: 2021/09/08 22:25:01 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;

	a = NULL;
	data = init_struct(argc, argv);
	if (!data)
		exit (0);
	sorting_arr(data);
	from_array(&a, data);
	b = ft_lstinit();
	if (whether_sorted(a, data) == 1)
		exit (0);
	if (data->size < 6)
		short_stack(&a, &b, data);
	else
		game(&a, &b, data);
	// if (whether_sorted(a, data) == 1) // delete
	// 	printf("Стек отсортирован (проверка в main)\n"); // delete
	// // printf("Отсортированный стек:\n"); //delete
	// // testing(a, b, data); // delete
	// printf("Количество чисел = %d\n", data->size); // delete
	// printf("Количество команд = %d\n", data->operations); // delete
	ft_allclear(&a, &b, data);
	return (0);
}
