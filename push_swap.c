/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:29:06 by abridger          #+#    #+#             */
/*   Updated: 2021/09/04 22:30:35 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;

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
	if (data->size < 5)
		short_stack(&a, &b, data);
	else
		game(&a, &b, data);
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
