/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:13:15 by abridger          #+#    #+#             */
/*   Updated: 2021/09/14 23:55:14 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*curr;

	temp = NULL;
	curr = NULL;
	if (*lst)
		curr = *lst;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*lst = NULL;
	temp = NULL;
	curr = NULL;
}

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
