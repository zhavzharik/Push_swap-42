/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:29:06 by abridger          #+#    #+#             */
/*   Updated: 2021/09/03 23:02:07 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;
	t_stack	*last;

	a = NULL;
	// if (argc == 2)
	// {
	// 	check_string(argc, argv);
	// 	array = ft_split(argv[1], ' ');
	// 	i = 1;
	// }
	// else
	data = init_struct(argc, argv);
	if (!data)
		exit (0);
	sorting_arr(data);
	from_array(&a, data);
	b = ft_lstinit();
	if (whether_sorted(a, data) == 1)
	{
		printf("Стек отсортирован изначально\n"); // delete
		exit (0);
	}
	testing(a, b, data); // delete
	last = ft_lstlast(a); //  выделить в функцию
	start_game(&a, &b, data, last); // add loop for game function
	process_game(&a, &b, data);
	update_max(&a, &b, data);
	if (whether_sorted(a, data) == 1) // delete
		printf("Стек отсортирован (проверка в мейн)\n"); // delete
	testing(a, b, data); // delete
	printf("Количество чисел = %d\n", data->size); // delete
	printf("Количество команд = %d\n", data->operations); // delete
	ft_allclear(&a, &b, data);
	return (0);
}

void	testing(t_stack *a, t_stack *b, t_data *data)
{
	printf("Стек А:\n");
	ft_print_stack(a, data);
	printf("Стек B:\n");
	ft_print_stack(b, data);
	printf("MID = %d\n", data->mid);
}
