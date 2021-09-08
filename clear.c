/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:13:15 by abridger          #+#    #+#             */
/*   Updated: 2021/09/08 22:43:50 by abridger         ###   ########.fr       */
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
}

void	ft_structclear(t_data *data)
{
	if (data)
	{
		if (data->array)
			free(data->array);
		if (data->sorted)
			free(data->sorted);
		free(data);
	}
}

void	ft_allclear(t_stack **a, t_stack **b, t_data *data)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_structclear(data);
}
