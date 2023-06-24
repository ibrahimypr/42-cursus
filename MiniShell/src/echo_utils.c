/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:16 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:13:17 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_echo_envp(t_envp *s_envp, int i, int j)
{
	while (s_envp->envp[i][++j])
	{
		if (s_envp->envp[i][j] == '=')
		{
			while (s_envp->envp[i][++j])
				ft_putchar_fd(s_envp->envp[i][j], 1);
		}
	}
}

static void	multiple_dollar(char *str, t_envp *s_envp)
{
	char	**dollars;
	int		i;
	char	*tmp;
	int		j;
	int		k;

	k = -1;
	dollars = ft_split(str, '$');
	while (dollars[++k])
	{
		i = -1;
		j = -1;
		while (s_envp->envp[++i])
		{
			tmp = ft_strjoin(dollars[k], "=\0");
			if (ft_isstartswith(s_envp->envp[i], tmp))
				print_echo_envp(s_envp, i, j);
			free(tmp);
		}
	}
	ft_free_str(dollars);
}

static void	get_my_env(char *var_name, t_envp *s_envp)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = -1;
	if (count(var_name, '$'))
		multiple_dollar(var_name, s_envp);
	while (s_envp->envp[++i])
	{
		tmp = ft_strjoin(var_name, "=\0");
		if (ft_isstartswith(s_envp->envp[i], tmp))
			print_echo_envp(s_envp, i, j);
		free(tmp);
	}
}

void	finder_dollar_env(char *s, int *i, t_envp *s_envp)
{
	char	*tmp;
	int		j;

	tmp = malloc(sizeof(char) * 75);
	j = 0;
	(*i)++;
	while (*(s + *i) != ' ' && *(s + *i))
	{
		tmp[j] = *(s + *i);
		(*i)++;
		j++;
	}
	get_my_env(tmp, s_envp);
	free(tmp);
}

void	sngle_quote_incheck(char *s, int *i)
{
	(*i)++;
	while (*(s + *i) != '\'' && *(s + *i))
	{
		ft_putchar_fd(*(s + *i), 1);
		(*i)++;
	}
}
