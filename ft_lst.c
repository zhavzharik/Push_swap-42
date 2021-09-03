/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:43:33 by abridger          #+#    #+#             */
/*   Updated: 2021/09/03 23:06:08 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstlastbutone(t_stack *lst)
{
	if (!lst)
		ft_puterror();
	if (lst->next == NULL)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstinit(void)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	new = NULL;
	return (new);
}

t_stack	*last_unsorted(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->flag == 0)
		lst = lst->next;
	return (lst);
}
