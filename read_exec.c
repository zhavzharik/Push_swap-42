/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:21:06 by abridger          #+#    #+#             */
/*   Updated: 2021/09/10 21:54:34 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reading_instr(int rd, char **line)
{
	int		i;
	char	ch;
	char	*buffer;

	buffer = malloc(100);
	*line = buffer;
	i = 0;
	while (rd > 0 && ch != '\n')
	{
		rd = read(1, &ch, 1);
		buffer[i++] = ch;
	}
	i++;
	buffer[i] = '\0';
	return (rd);
}

char	**create_array_instr(void)
{
	char	**instr;

	instr = (char **)malloc(12 * sizeof(char *));
	(*instr)[sa] = *ft_strdup("sa\n");
	(*instr)[sb] = *ft_strdup("sb\n");
	(*instr)[ss] = *ft_strdup("ss\n");
	(*instr)[pa] = *ft_strdup("pa\n");
	(*instr)[pb] = *ft_strdup("pb\n");
	(*instr)[ra] = *ft_strdup("ra\n");
	(*instr)[rb] = *ft_strdup("rb\n");
	(*instr)[rr] = *ft_strdup("rr\n");
	(*instr)[rra] = *ft_strdup("rra\n");
	(*instr)[rrb] = *ft_strdup("rrb\n");
	(*instr)[rrr] = *ft_strdup("rrr\n");
	(*instr)[12] = '\0';
	return (instr);
}

void	get_execute(t_stack **a, t_stack **b)
{
	char	*line;
	char	**instr;
	int		i;
	int		rd;

	i = 0;
	rd = 1;
	(void)a; // not used yet
	(void)b; // not used yet
	instr = create_array_instr();
	while (reading_instr(rd, &line))
	{
		while (instr[i] && ft_strcmp(instr[i], line))
			i++; // index function with instruction in array of functions
		//execute instructions;
	}
	free(instr); // rewrite and move into checker function
}
