/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:32:56 by iyapar            #+#    #+#             */
/*   Updated: 2022/02/12 10:49:22 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ff(long n)
{
	size_t	karakter;

	karakter = 0;
	if (n < 0)
	{
		karakter++;
		n = -n;
	}
	while (n >= 1)
	{
		karakter++;
		n = n / 10;
	}
	return (karakter);
}

static char	*ft_zz(char *rtn, long nbr, int len, int neg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup ("0"));
	if (!rtn)
		return (0);
	if (nbr < 0)
	{
		neg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (neg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		neg;

	nbr = n;
	len = ft_ff(nbr);
	rtn = 0;
	neg = 0;
	rtn = ft_zz(rtn, nbr, len, neg);
	if (!rtn)
		return (0);
	return (rtn);
}
