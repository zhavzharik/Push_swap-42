/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:30:20 by abridger          #+#    #+#             */
/*   Updated: 2021/09/09 21:49:30 by abridger         ###   ########.fr       */
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
	// if no numbers, stops and displays nothing
	if (!data)
		exit (0);
	sorting_arr(data);
	from_array(&a, data);
	b = NULL;
	if (whether_sorted(a, data) == 1) //?
		exit (0);
	// read instructions on the stundart input
	// Error, if not instructions or incorrect instructions
	// execute them
	if (whether_sorted(a, data) == 1 && !b) //?
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_allclear(&a, &b, data);
}
