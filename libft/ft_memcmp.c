/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:18:27 by iyapar            #+#    #+#             */
/*   Updated: 2022/02/16 13:13:27 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	if (n == 0)
		return (0);
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
	i++;
	}
	return (0);
}

// bellekte belirlenen 2 stringi n kadar karsilastirir
// eğer fark görürse farkını alıp döndürür aynıysa 0 döndürür
