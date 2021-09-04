/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:55:50 by abridger          #+#    #+#             */
/*   Updated: 2021/09/04 21:34:50 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_game(t_stack **a, t_stack **b, t_data *data)
{
	int		check;
	t_stack	*last;

	while (whether_sorted(*a, data) != 1 && (*a)->flag != 0)
	{
		last = ft_lstlast(*a);
		check = (*a)->flag;
		while ((*a)->flag == check && (*a)->flag != 0)
		{
			if ((*a)->indx == data->next && last->indx == data->next - 1) // check b
			{
				rotate(a, 1, data);
				data->next += 1;
			}
			else
				push(a, b, 2, data);
		}
		printf("Перекидываем в Б числа с одним флагом:\n"); //delete
		testing(*a, *b, data); // delete
		while (*b)  // выделить в отдельную функцию и добавить другой алгоритм при трех
		{
			update_mid(data);
			process_b(a, b, data);
		}
		printf("Сортируем Б:\n"); //delete
		testing(*a, *b, data); // delete
		while ((*a)->indx == data->next || (*a)->next->indx == data->next)
		{
			if ((*a)->next->indx == data->next)
				swap(a, 1, data);
			update_next(a, b, data);
		}
		printf("Если есть сл.число отправляем вниз, одновременно крутим Б, если надо:\n"); //delete
		testing(*a, *b, data); // delete
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
	int		len_b;
	int		check;

	update_max(data);
	unsorted = lastbutone_unsorted(*a);
	process_a(a, b, data, unsorted);
	printf("Снова делим несортированные числа и перекидываем в Б и вниз А:\n"); //delete
	testing(*a, *b, data); // delete
	update_mid(data);
	len_b = ft_lstsize(*b);
	check = ft_lstlast(*a)->flag;
	while (ft_lstlast(*a)->flag == check && ft_lstlast(*a)->indx != data->next - 1
		&& ft_lstlastbutone(*a)->indx != data->next - 2)
	{
		if (len_b > 3 && (*b)->indx != data->next) // && (*b)->next->indx != data->next)
			rev_rotate_two(a, b, data);
		else
			rev_rotate(a, 1, data);
	}
	printf("Крутим обратно А и если надо, то и Б:\n"); //delete
	testing(*a, *b, data); // delete
	while (*b) // переставлено update mid
	{
		process_b(a, b, data);
		update_mid(data);
	}
	printf("Перекидываем из Б обратно в А:\n"); //delete
	testing(*a, *b, data); // delete
	while ((*a)->indx == data->next || (*a)->next->indx == data->next)
	{
		if ((*a)->next->indx == data->next)
			swap(a, 1, data);
		update_next(a, b, data);
	}
	printf("Если есть след.число отправляем вниз, одновременно крутим Б, если надо:\n"); //delete
	testing(*a, *b, data); // delete
}

void	game(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	printf("Начало:\n"); // delete
	testing(*a, *b, data); // delete
	last = ft_lstlast(*a); //  выделить в функцию
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
