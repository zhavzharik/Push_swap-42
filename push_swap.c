/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:29:06 by abridger          #+#    #+#             */
/*   Updated: 2021/08/14 21:59:37 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		*array;
	int		*sorted;

	a = NULL;
	check_argv(argc, argv);
	i = 1;
	array = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	sorted = array; // написать функцию сортировки массива (нужно для индекса в сорт.списке)
	from_array(&a, array, sorted, i);
	ft_print_stack(a); // проверяем, что аргументы считываются и переносятся в стек а
	ft_print_order(a); // проверяем, какой порядок записан в стек
	return (0);
}
