/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:21:06 by abridger          #+#    #+#             */
/*   Updated: 2021/09/13 23:01:24 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reading_instr(int rd, char **line)
{
	int		i;
	char	ch;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 4 + 1);
	*line = buf;
	i = 0;
	while (rd > 0 && ch != '\n')
	{
		rd = read(STDIN_FILENO, &ch, 1);
		buf[i++] = ch;
	}
	buf[i] = '\n';
	buf[i++] = '\0';
	return (rd);
}

char	**create_array_instr(void)
{
	char	**instr;

	instr = (char **)malloc(12 * sizeof(char *));
	(instr)[sa] = ft_strdup("sa\n\0");
	(instr)[sb] = ft_strdup("sb\n\0");
	(instr)[ss] = ft_strdup("ss\n\0");
	(instr)[pa] = ft_strdup("pa\n\0");
	(instr)[pb] = ft_strdup("pb\n\0");
	(instr)[ra] = ft_strdup("ra\n\0");
	(instr)[rb] = ft_strdup("rb\n\0");
	(instr)[rr] = ft_strdup("rr\n\0");
	(instr)[rra] = ft_strdup("rra\n\0");
	(instr)[rrb] = ft_strdup("rrb\n\0");
	(instr)[rrr] = ft_strdup("rrr\n\0");
	(instr)[11] = NULL;
	return (instr);
}

t_action	*create_array_function(void)
{
	t_action	*array_func;

	array_func = NULL;
	array_func = (t_action *)malloc(12 * sizeof(t_action));
	(array_func)[sa] = &swap_a;
	(array_func)[sb] = &swap_b;
	(array_func)[ss] = &swap_s;
	(array_func)[pa] = &push_a;
	(array_func)[pb] = &push_b;
	(array_func)[ra] = &rotate_a;
	(array_func)[rb] = &rotate_b;
	(array_func)[rr] = &rotate_r;
	(array_func)[rra] = &rev_rotate_a;
	(array_func)[rrb] = &rev_rotate_b;
	(array_func)[rrr] = &rev_rotate_r;
	(array_func)[11] = NULL;
	return (array_func);
}

void	get_execute(t_stack **a, t_stack **b)
{
	char		*line;
	char		**instr;
	t_action	*func;
	int			i;
	int			rd;

	(void)a;
	(void)b;
	rd = 1;
	instr = create_array_instr();
	func = create_array_function();
	while (reading_instr(rd, &line))
	{
		i = 0;
		while (instr[i] && ft_strcmp(instr[i], line))
			i++;
		if (i > 10)
			ft_puterror();
		else
			(func)[i](a, b);
	}
	free(instr);
	free(func);
}
