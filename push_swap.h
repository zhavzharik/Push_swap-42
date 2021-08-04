/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:30:24 by abridger          #+#    #+#             */
/*   Updated: 2021/08/04 21:52:32 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack // for stack a or b array of strucrures
{
	int				nb;
	int				indx;
	int				flag;
	//struct s_stack	*prev;
	//struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				*input;
	int				*sorted;
	int				next;
	int				len_a;
	int				len_b;
	char			*action;
}					t_data;

void	ft_puterror(void);

#endif
