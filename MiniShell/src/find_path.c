/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:03 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:14:04 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*verify_path_simple(char *cmd, int i)
{
	char	**holder;
	char	*aux;
	char	*current_path;
	char	*path;

	holder = ft_split(getenv("PATH"), ':');
	while (holder[++i])
	{
		aux = ft_strdup(holder[i]);
		holder[i] = ft_strjoin(aux, "/");
		path = ft_strjoin(holder[i], cmd);
		if (aux[0] != '\0')
			free(aux);
		if (!access(path, F_OK))
		{
			current_path = ft_strdup(path);
			free(path);
			ft_free_str(holder);
			return (current_path);
		}
		free(path);
	}
	ft_free_str(holder);
	return (NULL);
}

char	*find_path_simple(char *cmd)
{
	char	*path;

	path = NULL;
	if (!access(cmd, F_OK))
		return (cmd);
	path = verify_path_simple(cmd, -1);
	if (path != NULL)
		return (path);
	return (NULL);
}

char	*verify_path(char *cmd, int i)
{
	char	**holder;
	char	*aux;
	char	*path;
	char	*current_path;

	holder = ft_split(getenv("PATH"), ':');
	while (holder[++i])
	{
		aux = ft_strdup(holder[i]);
		holder[i] = ft_strjoin(aux, "/");
		path = ft_strjoin(holder[i], cmd);
		if (aux[0] != '\0')
			free(aux);
		if (!access(path, F_OK))
		{
			current_path = ft_strdup(path);
			free(path);
			ft_free_str(holder);
			return (current_path);
		}
		free(path);
	}
	ft_free_str(holder);
	return (NULL);
}

char	*find_path(char *cmd)
{
	char	*path;

	path = NULL;
	if (!access(cmd, F_OK))
		return (cmd);
	path = verify_path(cmd, -1);
	if (path[0] != '\0')
		return (path);
	return (NULL);
}
