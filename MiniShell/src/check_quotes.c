/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:10 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:13:12 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_double_quote(char *str, int *i)
{
	(*i)++;
	while (*(str + *i) != '\"' && *(str + *i))
		(*i)++;
	if (*(str + *i) != '\"')
		return (-1);
	return (1);
}

static int	check_single_quote(char *str, int *i)
{
	(*i)++;
	while (*(str + *i) != '\'' && *(str + *i))
		(*i)++;
	if (*(str + *i) != '\'')
		return (-1);
	return (1);
}

int	check_quotes(char *s, t_utils utils)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			utils.quote_flag = check_double_quote(s, &i);
		else if (s[i] == '\'')
			utils.quote_flag = check_single_quote(s, &i);
		if (utils.quote_flag == -1)
			break ;
		i++;
	}
	return (utils.quote_flag);
}
