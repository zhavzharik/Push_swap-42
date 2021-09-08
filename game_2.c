/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:55:50 by abridger          #+#    #+#             */
/*   Updated: 2021/09/08 22:16:47 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_game(t_stack **a, t_stack **b, t_data *data)
{
	int		check;
	t_stack	*last;

	while (whether_sorted(*a, data) != 1 && (*a)->flag != 0)
	{
		check = (*a)->flag;
		while ((*a)->flag == check && (*a)->flag != 0)
		{
			last = ft_lstlast(*a);
			if ((*a)->indx == data->next && last->indx == data->next - 1)
			{
				rotate(a, 1, data);
				data->next += 1;
			}
			else
				push(a, b, 2, data);
		}
		sort_b(a, b, data);
		check_topalast(a, b, data);
	}
	// printf("End process_game\n"); //delete
	// testing(*a, *b, data); // delete
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

	if (whether_sorted(*a, data) != 1)
	{
		update_max(data);
		unsorted = lastbutone_unsorted(*a);
		process_a(a, b, data, unsorted);
		update_mid(data, b);
		while (ft_lstlast(*a)->flag == 0 && (*b)->indx != data->next)
			rev_rotate_two(a, b, data);
		while (ft_lstlast(*a)->flag == 0
			&& ft_lstlast(*a)->indx != data->next - 1
			&& ft_lstlastbutone(*a)->indx != data->next - 2)
			rev_rotate(a, 1, data);
		// printf("After rev_rotate in process_unsorted\n");
		// testing(*a, *b, data); // delete
		while (*b) // && whether_sorted(*a, data) != 1)
		{
			// printf("Start while B in process_unsorted\n"); // delete
			process_b(a, b, data);
			// printf("In while B in process_unsorted\n"); // delete
			// testing(*a, *b, data); // delete
			update_mid(data, b);
		}
		// printf("After while b in process_unsorted\n");
		// testing(*a, *b, data); // delete
		check_topa(a, b, data);
	}
	// printf("End process_unsorted\n");
	// testing(*a, *b, data); // delete
	// if (whether_sorted(*a, data) == 1) // delete
	// 	printf("Стек отсортирован (проверка в process_unsorted)\n"); // delete
}

void	game(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*last;

	last = ft_lstlast(*a);
	start_game(a, b, data, last);
	while (whether_sorted(*a, data) != 1)
	{
		process_game(a, b, data);
		update_max(data);
		process_unsorted(a, b, data);
		// if (whether_sorted(*a, data) == 1) // delete
		// 	printf("Стек отсортирован (проверка в game)\n"); // delete
	}
}

void	check_topa(t_stack **a, t_stack **b, t_data *data)
{
	while ((*a)->indx == data->next || (*a)->next->indx == data->next)
	{
		if ((*a)->next->indx == data->next)
		{
			if (!(*b) || ((*b) && !(*b)->indx)
				|| ((*b) && (*b)->indx == data->next + 1))
				swap(a, 1, data);
			else
				swap(a, 1, data);
				// swap_two(a, b, data); // возникает ошибка, это последний элемент, нужно условие, что это не last тогда swap_two
		}
		update_next(a, b, data);
	}
}
