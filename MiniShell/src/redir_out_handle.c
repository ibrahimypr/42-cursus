/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:41 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:14:42 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_another_redir(char **str, int i)
{
	int		pos;

	pos = i + 2;
	while (str[pos])
	{
		if (str[pos + 1] && (ft_strncmp(str[pos], ">", 1) == 0 || \
			ft_strncmp(str[pos], ">>", 2) == 0))
		{
			open(str[pos - 1], O_CREAT, 0777);
			if (str[pos + 2] == NULL)
			{
				i = pos;
				break ;
			}
		}
		pos = pos + 2;
	}
	return (i);
}

void	redir_out_handle(char **str, int i, t_envp *s_envp)
{
	t_redir_var	variables;

	variables.j = 0;
	variables.m = 0;
	variables.k = 0;
	variables.temp = (char *)malloc(sizeof(char) * 100);
	variables.flags = O_WRONLY | O_CREAT;
	if (str[i + 2])
		i = check_another_redir(str, i);
	variables.file = ft_strdup(str[i + 1]);
	while (ft_strncmp(str[variables.k], ">", 1))
	{
		variables.m = 0;
		while (str[variables.k][variables.m])
			variables.temp[variables.j++] = str[variables.k][variables.m++];
		variables.temp[variables.j] = ' ';
		variables.j++;
		variables.k++;
	}
	variables.temp[variables.j - 1] = '\0';
	variables.fd = open(variables.file, variables.flags | O_TRUNC, 0777);
	execute_dir(variables.temp, variables.fd, 1, s_envp);
	free(variables.file);
	free(variables.temp);
}

void	redir2_out_handle(char **str, int i, t_envp *s_envp)
{
	char	*temp;
	int		fd;
	int		flags;
	char	*file;

	flags = O_WRONLY | O_CREAT;
	temp = sub_redir(str, i);
	if (str[i + 2])
		i = check_another_redir(str, i);
	file = ft_strdup(str[i + 1]);
	fd = open(file, flags | O_APPEND, 0777);
	execute_dir(temp, fd, 1, s_envp);
	if (temp[0] != '\0')
		free(temp);
	if (file[0] != '\0')
		free(file);
}
