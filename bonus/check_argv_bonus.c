/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:48:52 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 21:48:41 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	check_first_ch(int c)
{
	if (c == 45 || c == 43 || (c <= 57 && c >= 48))
		return (1);
	else
		return (0);
}

int	sign(int c)
{
	if (c == 45 || c == 43)
		return (1);
	else
		return (0);
}

void	check_argv(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	while (i < argc)
	{
		if (!check_first_ch(argv[i][0]))
			ft_puterror();
		if (sign(argv[i][0]) && !argv[i][1])
			ft_puterror();
		len = 1;
		while (len < ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][len]) != 1)
				ft_puterror();
			len++;
		}
		i++;
	}
}

void	check_duplicate(int argc, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (data->array[i] == data->array[j])
				ft_puterror();
			j++;
		}
		i++;
	}
}
