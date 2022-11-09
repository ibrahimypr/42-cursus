/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:06:30 by iyapar            #+#    #+#             */
/*   Updated: 2022/06/29 15:06:32 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_swap_a(t_struct **stackA)
{
	t_struct	*head;

	if (stackA && (*stackA)->next != NULL)
	{
		head = (*stackA)->next;
		(*stackA)->next = head->next;
		head->next = *stackA;
		*stackA = head;
	}
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_struct **stackB)
{
	t_struct	*head;

	if (stackB && (*stackB)->next != NULL)
	{
		head = (*stackB)->next;
		(*stackB)->next = head->next;
		head->next = *stackB;
		*stackB = head;
	}
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_struct **stackA, t_struct **stackB)
{
	ft_swap_a(stackA);
	ft_swap_b(stackB);
}
