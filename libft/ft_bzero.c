/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:49:13 by iyapar            #+#    #+#             */
/*   Updated: 2022/02/02 16:18:45 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*asdf;

	i = 0;
	asdf = (char *)s;
	while (i < n)
	{
		asdf[i] = 0;
		i++;
	}
	s = asdf;
}

// bir stringde istedigimiz kadar index sayisini 0 ile doldurur
