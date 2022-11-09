/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:06:44 by iyapar            #+#    #+#             */
/*   Updated: 2022/06/30 16:34:42 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_push_small_a(t_struct **stackA, t_struct **stackB, int flag)
{
	t_struct	*head;

	head = *stackA;
	while (head->next != NULL)
	{
		if (head->index == 0 && flag == 0)
		{
			ft_push_b(stackA, stackB);
			break ;
		}
		if (head->index == 1 && flag == 1)
		{
			ft_push_b(stackA, stackB);
			break ;
		}
		ft_rot_a(stackA);
		head = *stackA;
	}
	free (head);
}

// en küçük en üste gelene kadar rotate a yapıyor 
//en küçük en üste geldiğinde b ye pushlayıp tekrar a ya pushluyor
