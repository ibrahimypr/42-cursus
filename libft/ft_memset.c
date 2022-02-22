/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:39:00 by iyapar            #+#    #+#             */
/*   Updated: 2022/01/31 11:53:03 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *word, int latter, size_t length)
{
	size_t	index;
	char	*new_word;

	index = 0;
	new_word = (char *) word;
	while (index < length)
	{
		new_word[index] = latter;
		index++;
	}
	return (new_word);
}

// bellekte bir kelimede istenilen bir harfle istenilen uzunluk kadar
// yer degistirir
