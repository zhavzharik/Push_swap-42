/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:16:55 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 17:51:26 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long	number;

	number = (long long) n;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr(number / 10);
	ft_putchar((number % 10) + '0');
}
