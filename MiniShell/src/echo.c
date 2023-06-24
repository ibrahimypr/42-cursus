/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:23 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:13:24 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_handle(char *s, t_utils utils, t_envp *s_envp)
{
	utils.quote_flag = 1;
	if (check_quotes(s, utils) == -1)
	{
		g_return = 127;
		ft_putstrendl_fd("Syntax Error Occured!", 1);
	}
	else
	{
		if (utils.n_flag == 1)
			echo_withn(s, s_envp);
		else if (utils.n_flag == -1)
			echo_withoutn(s, s_envp);
	}
}

static char	*find_start_n(char *str, int last, int start)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i - 1] == ' ' && (str[i] == '-' && str[i + 1] == 'n')
			&& str[i + 2] == ' ')
		{
			i += 2;
			while (str[i] < 33)
				i++;
			start = i;
			break ;
		}
		i++;
	}
	tmp = ft_echo_substr(str, start, last + 1);
	if (tmp[0] != '\0')
		return (tmp);
	return (NULL);
}

static char	*find_start(char *str, int last, int start)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] > 32)
			;
		else
		{
			i++;
			while (str[i] < 33)
				i++;
			start = i;
			break ;
		}
		i++;
	}
	tmp = ft_echo_substr(str, start, last + 1);
	return (tmp);
}

static char	*ft_split_echo(char *str, t_utils utils)
{
	int		last;
	int		start;
	int		len;
	char	*tmp;

	last = 0;
	start = 0;
	len = ft_strlen(str) - 1;
	while (len)
	{
		if (str[len] > 32 && str[len] <= 127)
		{
			last = len;
			str[last + 1] = '\0';
			break ;
		}
		len--;
	}
	if (utils.n_flag == 1)
		tmp = find_start_n(str, last, start);
	else
		tmp = find_start(str, last, start);
	return (tmp);
}

void	echo_canalizer(char *str, t_envp *s_envp)
{
	t_utils	utils;
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strtrim(str, " ");
	utils.n_flag = n_check(str);
	tmp = ft_split_echo(tmp2, utils);
	echo_handle(tmp, utils, s_envp);
	if (tmp[0] != '\0')
		free(tmp);
	if (tmp2[0] != '\0')
		free(tmp2);
}
