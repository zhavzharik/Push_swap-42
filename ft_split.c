/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:26:07 by abridger          #+#    #+#             */
/*   Updated: 2021/08/17 22:12:40 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_go_space(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
			return (i);
	}
	return (i);
}

static size_t	ft_go_str(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			i++;
		if (s[i] == c)
			return (i);
	}
	if (s[i] == c)
		return (i);
	return (i);
}

size_t	ft_words_nb(char const *s, char c)
{
	size_t	nb;
	size_t	i;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] && s[i + 1] == c)
			    || (s[i] != c && !s[i + 1]))
			nb++;
		i++;
	}
	return (nb);
}

int	*ft_split(char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;
	int		*array;

	if (!s)
		return (NULL);
	array = (int *)malloc(sizeof(int) * (ft_words_nb(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	len = 0;
	j = 0;
	while (j < ft_words_nb(s, c))
	{
		i = i + len + ft_go_space(&s[i + len], c);
		len = ft_go_str(&s[i], c);
		if (ft_atoi(&s[i + len])) // проверить числа после слова
			array[j] = ft_atoi(&s[i + len]);
		else
			ft_puterror(); //в этом цикле ошибка
		j++;
	}
	return (array);
}

// int	main(int argc, char **argv)
// {
// 	int		*array;
// 	size_t	len;

// 	array = ft_split(argv[1], ' ');
// 	len = ft_words_nb(argv[1], ' ');
// 	while (len-- > 0)
// 		ft_putnbr(array[len]);
// 	return (0);
// }
