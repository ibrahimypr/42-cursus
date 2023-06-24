/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:59 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:14:00 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export(char *var_name, char *var_val, t_envp *s_envp)
{
	int		i;

	i = get_index(var_name, s_envp);
	if (s_envp->envp[i])
		export_run_exist(var_name, var_val, s_envp, i);
	else if (s_envp->envp[i] == NULL)
		export_run_nonexistent(var_name, var_val, s_envp, i);
}

void	export_with_equal(char **s, t_envp *s_envp, int i)
{
	char	*temp;
	char	*temp2;
	int		j;
	int		k;

	j = 0;
	k = 0;
	temp = (char *)malloc(sizeof(char) * 20);
	temp2 = (char *)malloc(sizeof(char) * 20);
	while (s[i][j] != '=')
		temp[k++] = s[i][j++];
	temp[k] = '\0';
	k = 0;
	if (s[i][j] == '=')
	{
		while (s[i][j] != '\0')
			temp2[k++] = s[i][++j];
		temp2[k] = '\0';
	}
	export(temp, temp2, s_envp);
	free(temp);
	free(temp2);
}

void	export_handle2(char *sub2, t_envp *s_envp)
{
	int		i;
	char	**s;
	int		equal;

	s = ft_split(sub2, ' ');
	i = -1;
	free(sub2);
	while (s[++i])
	{
		equal = count(s[i], '=');
		if (equal > 0)
			export_with_equal(s, s_envp, i);
		else if (equal == 0)
			export(s[i], NULL, s_envp);
	}
	ft_free_str(s);
}

void	export_handle(char *str, t_envp *s_envp)
{
	char	*sub;
	char	*sub2;
	int		len;

	len = ft_strlen(str);
	sub = ft_substr(str, 7, len - 7);
	sub2 = ft_strtrim(sub, " ");
	if (sub2[0] == '\0')
	{
		print_export(s_envp);
		free(sub2);
	}
	else
		export_handle2(sub2, s_envp);
	free(sub);
}
