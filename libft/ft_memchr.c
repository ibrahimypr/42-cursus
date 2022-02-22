/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:04 by iyapar            #+#    #+#             */
/*   Updated: 2022/02/03 11:40:15 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pts;
	unsigned char	cc;

	pts = (void *)s;
	cc = c;
	i = 0;
	while (i < n)
	{
		if ((pts[i] - cc) == 0)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

// bir stringdeki bir kelimenin bellekteki değerini döndürür
