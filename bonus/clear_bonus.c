/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:13:15 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:17:11 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_structclear(t_data *data)
{
	if (data)
	{
		if (data->array)
		{
			free(data->array);
			data->array = NULL;
		}
		if (data->sorted)
		{
			free(data->sorted);
			data->array = NULL;
		}
		free(data);
		data = NULL;
	}
}

void	ft_allclear(t_stack **a, t_stack **b, t_data *data)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_structclear(data);
}

void	ft_array_clear(char **instr, t_action *func)
{
	int		i;
	char	*temp;

	i = 0;
	if (!instr)
		return ;
	while (i < 11)
	{
		temp = instr[i++];
		free(temp);
		temp = NULL;
	}
	free(instr);
	*instr = NULL;
	if (func)
		free(func);
}
