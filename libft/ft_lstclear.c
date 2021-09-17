/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:05:12 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 18:32:14 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
