/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:29:06 by abridger          #+#    #+#             */
/*   Updated: 2021/08/28 14:30:50 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		*array;
	int		*sorted;

	a = NULL;
	if (argc == 2)
	{
		check_string(argc, argv);
		array = ft_split(argv[1], ' ');
		i = 1;
	}
	else
	{
		i = 1;
		check_argv(argc, argv);
		array = (int *)malloc(sizeof(int) * (argc - 1));
		while (i < argc)
		{
			array[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		check_duplicate(argc, array);
	}
	sorted = sorting_arr(array, argc - 1);
	from_array(&a, array, sorted, i);
	b = ft_lstinit();
	testing(a, b);
	return (0);
}

void	testing(t_stack *a, t_stack *b)
{
	printf("Стек А:\n");
	ft_print_stack(a);
	printf("Порядок:\n");
	ft_print_order(a);
	printf("Проверка rotate:\n");
	rotate(&a, 1);
	ft_print_stack(a);
	printf("Проверка swap:\n");
	swap(&a, 1);
	ft_print_stack(a);
	printf("Проверка reverse rotate:\n");
	rev_rotate(&a, 1);
	ft_print_stack(a);
	printf("Проверка push b:\n");
	push(&a, &b, 2);
	printf("Стек В:\n");
	ft_print_stack(b);
	printf("Стек А:\n");
	ft_print_stack(a);
	printf("Проверка push b:\n");
	push(&a, &b, 2);
	printf("Стек В:\n");
	ft_print_stack(b);
	printf("Стек А:\n");
	ft_print_stack(a);
	printf("Проверка rotate a and b:\n");
	rotate_two(&a, &b);
	printf("Стек В:\n");
	ft_print_stack(b);
	printf("Стек А:\n");
	ft_print_stack(a);
	printf("Проверка push b:\n");
	push(&a, &b, 2);
	printf("Стек В:\n");
	ft_print_stack(b);
	printf("Стек А:\n");
	ft_print_stack(a);
	printf("Проверка rotate a and b:\n");
	rotate_two(&a, &b);
	printf("Стек В:\n");
	ft_print_stack(b);
	printf("Стек А:\n");
	ft_print_stack(a);
	printf("Проверка reverse rotate a and b:\n");
	rev_rotate_two(&a, &b);
	printf("Стек В:\n");
	ft_print_stack(b);
	printf("Стек А:\n");
	ft_print_stack(a);
	printf("Проверка push a:\n");
	push(&b, &a, 1);
	printf("Стек В:\n");
	ft_print_stack(b);
	printf("Стек А:\n");
	ft_print_stack(a);
}
