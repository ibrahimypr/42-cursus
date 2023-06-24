/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:32 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:13:33 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_len(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

int	ft_isstartswith(char *s1, char *s2)
{
	int	i;

	i = -1;
	if (!s2)
	{
		ft_putstrendl_fd("Error Occured!", 1);
		g_return = 127;
	}
	while (s2[++i])
		if (s2[i] && s1[i] != s2[i])
			return (0);
	return (1);
}

int	get_index(char *var_name, t_envp *s_envp)
{
	int		i;

	i = -1;
	while (s_envp->envp[++i])
	{
		if (ft_isstartswith(s_envp->envp[i], var_name))
		{
			return (i);
		}
	}
	return (i);
}

void	realloc_envp(t_envp *s_envp)
{
	char	**new_env;
	int		i;

	new_env = (char **)malloc(sizeof(char *) * (s_envp->env_len * 2));
	if (!new_env)
	{
		ft_putstrendl_fd("Malloc Failed!", 1);
		g_return = 127;
	}
	i = 0;
	while (s_envp->envp[i])
	{
		new_env[i] = ft_strdup(s_envp->envp[i]);
		free(s_envp->envp[i]);
		i++;
	}
	new_env[i] = NULL;
	free(s_envp->envp);
	s_envp->envp = new_env;
}
