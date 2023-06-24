/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:55 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:14:56 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*sub_redir(char **str, int i)
{
	char	*temp;
	int		m;
	int		k;
	int		j;

	j = 0;
	k = -1;
	temp = (char *)malloc(sizeof(char) * 100);
	while (++k < i)
	{
		m = 0;
		while (str[k][m])
			temp[j++] = str[k][m++];
		temp[j] = ' ';
		j++;
	}
	temp[j - 1] = '\0';
	return (temp);
}

int	count(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}
