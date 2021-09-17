/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:12:54 by abridger          #+#    #+#             */
/*   Updated: 2021/09/17 18:50:28 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	int				indx;
	int				flag;
	struct s_stack	*next;
}					t_stack;

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_puterror(void);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char *s1);
void	ft_lstadd_front(t_stack **a, int number, int index);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **lst);

#endif
