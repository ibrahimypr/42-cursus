/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:16:23 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:16:24 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	counter(const char *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i++])
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

char	*ft_strndup(const char *s, unsigned int n)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL || !s || !str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	d;
	char			**table;

	a = 0;
	d = 0;
	table = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (table == NULL || !s)
		return (NULL);
	while (s[a])
	{
		while (s[a] == c)
			a++;
		b = a;
		while (s[a] && s[a] != c)
			a++;
		if (b < a)
			table[d++] = ft_strndup(s + b, a - b);
	}
	table[d] = NULL;
	return (table);
}
