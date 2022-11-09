/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:05:14 by iyapar            #+#    #+#             */
/*   Updated: 2022/06/30 16:50:15 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_struct
{
	int				value;
	int				index;
	struct s_struct	*next;
}t_struct;

//is
bool		ft_isdigit(int c);

//to
long		ps_atoll(char *str);
int			ft_atoi(const char *str);

//bonus
t_struct	*ft_lstnew(int value);
void		ft_lstadd_front(t_struct **lst, t_struct *new);
int			ft_lstsize(t_struct *lst);
t_struct	*ft_lstlast(t_struct *lst);
void		ft_lstadd_back(t_struct **lst, t_struct *new);

#endif
