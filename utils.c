/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:48:52 by abridger          #+#    #+#             */
/*   Updated: 2021/08/14 22:20:52 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterror(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int	ft_isalpha(int c)
{
	if ((c <= 90 && c >= 65) || (c <= 122 && c >= 97))
		return (1);
	else
		return (0);
}

void	check_argv(int argc, char **argv) // add check duplicate, string (argc=2), max_int
{
	int	i;
	int	len;

	i = 1;
	if (argc <= 1)
		ft_puterror();
	while (i < argc)
	{
		len = 0;
		while (len < ft_strlen(argv[i]))
		{
			if (ft_isalpha(argv[i][len]) == 1)
				ft_puterror();
			len++;
		}
		i++;
	}
}
