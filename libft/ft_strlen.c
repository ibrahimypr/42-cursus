/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:21:55 by iyapar            #+#    #+#             */
/*   Updated: 2022/02/02 14:31:00 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}