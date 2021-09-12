/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:21:06 by abridger          #+#    #+#             */
/*   Updated: 2021/09/12 20:21:06 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reading_instr(int rd, char **line)
{
	int		i;
	char	ch;
	char	*buffer;

	buffer = malloc(128);
	*line = buffer;
	i = 0;
	while (rd > 0 && ch != '\n')
	{
		rd = read(STDIN_FILENO, &ch, 1);
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

t_action	*create_array_function(void)
{
	t_action	*array_func;

	array_func = NULL;
	array_func = (t_action *)malloc(11 * sizeof(t_action));
	array_func[sa] = swap_a;
	array_func[sb] = swap_b;
	array_func[ss] = swap_s;
	array_func[pa] = push_a;
	array_func[pb] = push_b;
	array_func[ra] = rotate_a;
	array_func[rb] = rotate_b;
	array_func[rr] = rotate_r;
	array_func[rra] = rev_rotate_a;
	array_func[rrb] = rev_rotate_b;
	array_func[rrr] = rev_rotate_r;
	return (array_func);
}

void	get_execute(t_stack **a, t_stack **b)
{
	char		*line;
	char		**instr;
	t_action	*func;
	int			i;
	int			rd;

	i = 0;
	rd = 1;
	instr = create_array_instr();
	func = create_array_function();
	while (reading_instr(rd, &line))
	{
		while (instr[i] && ft_strcmp(instr[i], line))
			i++; // index function with instruction in array of functions
		func[i](a, b);//execute instructions;
	}
	free(instr); // rewrite?
	free(func);
}
