/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:03 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:13:05 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_cd(char *tmp)
{
	char	*sub;
	int		len;

	len = ft_strlen(tmp);
	sub = ft_substr(tmp, 3, len - 3);
	if (sub[0] == '\0' || sub[0] == '~')
	{
		sub = ft_strdup(getenv("HOME"));
	}
	g_return = chdir(sub);
	free(sub);
	if (g_return < 0)
		ft_putstrendl_fd("cd: no such file or directory", 1);
}
