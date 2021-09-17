/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:43:33 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 19:25:48 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_stack	*ft_lstlastbutone(t_stack *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

// t_stack	*lastbutone_unsorted(t_stack *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next->flag == 0)
// 		lst = lst->next;
// 	return (lst);
// }
