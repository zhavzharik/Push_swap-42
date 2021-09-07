/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:55:50 by abridger          #+#    #+#             */
/*   Updated: 2021/09/07 23:45:01 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_game(t_stack **a, t_stack **b, t_data *data)
{
	int		check;
	t_stack	*last;
	int 	i; // delete
	// int		len_b;
	i = 0; // delete
	while (whether_sorted(*a, data) != 1 && (*a)->flag != 0)
	{
		// last = ft_lstlast(*a);
		// check_topb(a, b, data);
		check = (*a)->flag;
		while ((*a)->flag == check && (*a)->flag != 0)
		{
			// if ((*a)->next->indx == data->next)
			// {
			// 	if (!(*b) || !(*b)->next || (*b)->next->nb > (*b)->nb)
			// 		swap(a, 1, data);
			// 	else
			// 		swap_two(a, b, data);
			// }
			last = ft_lstlast(*a);
			if ((*a)->indx == data->next && last->indx == data->next - 1) // check b
			{
				rotate(a, 1, data);
				data->next += 1;
				// check_topb(a, b, data);
			}
			else
				push(a, b, 2, data);
		}
		printf("Перекидываем в Б числа с одним флагом:\n"); //delete
		testing(*a, *b, data); // delete
		while (*b)  // выделить в отдельную функцию и добавить другой алгоритм при трех
		{
			update_mid(data, b);
			printf("MID = %d\n", data->mid); // delete
			printf("MAX = %d\n", data->max); // delete
			printf("Next = %d\n", data->next); // delete
			process_b(a, b, data);
			printf("Сортируем Б %d раз:\n", i); //delete
			testing(*a, *b, data); // delete
			// update_mid(data, b);
			// len_b = ft_lstsize(*b);
			// if (len_b == 3 || len_b == 2)
			// {
			// 	stack_two(b, data);
			// 	stack_three(b, 2, data);
			// }
			i++;
		}
		// printf("Сортируем Б:\n"); //delete
		// testing(*a, *b, data); // delete
		// check_topa(a, b, data);
		while ((*a)->indx == data->next || (*a)->next->indx == data->next)
		{
			last = ft_lstlast(*a); // не сыграло
			if ((*a)->next->indx == data->next && last->indx == data->next - 1)
				swap(a, 1, data);
			update_next(a, b, data);
			// check_topb(a, b, data);
		}
		// printf("Если есть сл.число отправляем вниз, одновременно крутим Б, если надо:\n"); //delete
		// testing(*a, *b, data); // delete
	}
}

void	update_max(t_data *data)
{
	if (data)
	{
		data->max = data->size;
		data->mid = (data->max - data->next) / 2 + data->next;
	}
}

void	process_unsorted(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*unsorted;
	int		i; // delete
	// int		len_b;
	// int		check;

	i = 0; // delete
	update_max(data);
	unsorted = lastbutone_unsorted(*a);
	process_a(a, b, data, unsorted);
	printf("Снова делим несортированные числа и перекидываем в Б и вниз А:\n"); //delete
	testing(*a, *b, data); // delete
	update_mid(data, b);
	// len_b = ft_lstsize(*b);
	// check = ft_lstlast(*a)->flag;
	while (ft_lstlast(*a)->flag == 0 && (*b)->indx != data->next) // && ft_lstlast(*a)->indx != data->next - 1
		// && ft_lstlastbutone(*a)->indx != data->next - 2)
		// if (len_b > 3 && (*b)->indx != data->next) // && (*b)->next->indx != data->next)
		rev_rotate_two(a, b, data);
	while (ft_lstlast(*a)->flag == 0 && ft_lstlast(*a)->indx != data->next - 1
		&& ft_lstlastbutone(*a)->indx != data->next - 2)
		rev_rotate(a, 1, data);
	printf("Крутим обратно А и если надо, то и Б:\n"); //delete
	testing(*a, *b, data); // delete
	while (*b) // переставлено update mid
	{
		// update_mid(data);
		process_b(a, b, data);
		printf("Сортируем Б %d раз:\n", i); //delete
		testing(*a, *b, data); // delete
		// len_b = ft_lstsize(*b);
		// if (len_b == 3 || len_b == 2)
		// {
		// 	stack_two(b, data);
		// 	stack_three(b, 2, data);
		// }
		update_mid(data, b);
		i++;
	}
	printf("Перекидываем из Б обратно в А:\n"); //delete
	testing(*a, *b, data); // delete
	check_topa(a, b, data);
	// while ((*a)->indx == data->next || (*a)->next->indx == data->next)
	// {
	// 	if ((*a)->next->indx == data->next)
	// 		swap(a, 1, data);
	// 	update_next(a, b, data);
	// }
	printf("Если есть след.число отправляем вниз, одновременно крутим Б, если надо:\n"); //delete
	testing(*a, *b, data); // delete
}

void	game(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	printf("Начало:\n"); // delete
	testing(*a, *b, data); // delete
	last = ft_lstlast(*a);
	start_game(a, b, data, last);
	printf("Первая сортировка А и Б:\n"); //delete
	testing(*a, *b, data); // delete
	while (whether_sorted(*a, data) != 1)
	{
		process_game(a, b, data);
		update_max(data);
		process_unsorted(a, b, data);
	}
	if (whether_sorted(*a, data) == 1) // delete
		printf("Стек отсортирован (проверка в game)\n"); // delete
	printf("Отсортированный стек:\n"); //delete
	testing(*a, *b, data); // delete
	printf("Количество чисел = %d\n", data->size); // delete
	printf("Количество команд = %d\n", data->operations); // delete
}

void	check_topa(t_stack **a, t_stack **b, t_data *data)
{
	while ((*a)->indx == data->next || (*a)->next->indx == data->next)
	{
		if ((*a)->next->indx == data->next)
		{
			if (!(*b) || ((*b) && (*b)->indx == data->next + 1))
			// if ((!(*b) || !(*b)->next) || (*b)->next->nb > (*b)->nb) // sign
				swap(a, 1, data);
			else
				swap_two(a, b, data);
		}
		update_next(a, b, data);
	}
}
