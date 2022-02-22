/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:41:03 by iyapar            #+#    #+#             */
/*   Updated: 2022/02/02 17:10:01 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*str1;
	const unsigned char	*str2;

	if (!dest && !src)
		return (0);
	str1 = dest;
	str2 = src;
	while (n-- > 0)
	{
		*str1++ = *str2++;
	}
	return (dest);
}

// src'yi dest'e kopyalar fakat çakışmalar olabilir
