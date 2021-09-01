/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:29:06 by abridger          #+#    #+#             */
/*   Updated: 2021/09/01 20:06:27 by abridger         ###   ########.fr       */
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
	sorting_arr(data);
	from_array(&a, data);
	b = ft_lstinit();
	start_game(&a, &b, data);
	ft_allclear(&a, &b, data);
	return (0);
}

void	testing(t_stack *a, t_stack *b, t_data *data)
{
	printf("Стек А:\n");
	ft_print_stack(a);
	printf("Стек B:\n");
	ft_print_stack(b);
	printf("MID = %d\n", data->mid);
}
