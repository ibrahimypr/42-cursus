/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:28:08 by iyapar            #+#    #+#             */
/*   Updated: 2022/02/03 17:34:42 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src)
		return (dest);
	else if (dest < src)
		dest = ft_memcpy(dest, src, n);
	else
	{
		d = (unsigned char *)dest;
		s = (const unsigned char *)src;
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

// memcpy'den farkı çakışmaları önler
