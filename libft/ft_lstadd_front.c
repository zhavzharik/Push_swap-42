/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:19:24 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 18:50:05 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack **a, int number, int index)
{
	t_stack	*tmp;

	tmp = (t_stack *) malloc(sizeof(t_stack));
	if (!tmp)
		ft_puterror();
	tmp->nb = number;
	tmp->indx = index;
	tmp->flag = 0;
	tmp->next = (*a);
	(*a) = tmp;
}
