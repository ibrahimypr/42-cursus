/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:26:18 by iyapar            #+#    #+#             */
/*   Updated: 2022/02/03 11:26:45 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index++;
	}
	if (c == '\0')
		return ((char *)(str + index));
	return (NULL);
}

// soldan baslayarak bir kelimede istedigimiz kelimeyi bulunca
// devamını döndürür
// '\0' gönderilirse de dizenin sonunu göstereceği için
// hiç bir şey görmeyiz boş gönderirse de null değer döndürür
