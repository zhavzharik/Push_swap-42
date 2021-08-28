/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:48:52 by abridger          #+#    #+#             */
/*   Updated: 2021/08/28 16:12:52 by abridger         ###   ########.fr       */
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

void	check_argv(int argc, char **argv) // add check MAX_INT
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

void	check_string(int argc, char **argv) // need to fix
{
	int		i;
	int		j;
	int		*array;

	if (argc == 2)
		array = ft_split(argv[argc - 1], ' ');
	i = 0;
	while (i < (int)ft_words_nb(argv[argc - 1], ' '))
	{
		j = i + 1;
		while (j < (int)ft_words_nb(argv[argc - 1], ' '))
		{
			if (array[i] == array[j])
				ft_puterror();
			j++;
		}
		i++;
	}
	free(array);
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
