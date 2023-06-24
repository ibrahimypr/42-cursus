/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:19 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:13:20 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dble_quote_incheck(char *s, int *i)
{
	(*i)++;
	while (*(s + *i) != '\"' && *(s + *i))
	{
		ft_putchar_fd(*(s + *i), 1);
		(*i)++;
	}
}

void	echo_withn(char *s, t_envp *s_envp)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			dble_quote_incheck(s, &i);
		else if (s[i] == '\'')
			sngle_quote_incheck(s, &i);
		else if (s[i] == '$' && s[i + 1] == '?' && ++i)
			ft_putnbr_fd(g_return, 1);
		else if (s[i] == '$')
			finder_dollar_env(s, &i, s_envp);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
}

void	echo_withoutn(char *s, t_envp *s_envp)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			dble_quote_incheck(s, &i);
		else if (s[i] == '\'')
			sngle_quote_incheck(s, &i);
		else if (s[i] == '$' && s[i + 1] == '?' && ++i)
			ft_putnbr_fd(g_return, 1);
		else if (s[i] == '$')
			finder_dollar_env(s, &i, s_envp);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

char	*ft_echo_substr(char *str, int start, int end)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (end - start) + 1);
	while (start < end)
	{
		tmp[i] = str[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	n_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (str[i - 1] == ' ' && (str[i] == '-'
			&& str[i + 1] == 'n') && str[i + 2] == ' ')
		return (1);
	return (-1);
}
