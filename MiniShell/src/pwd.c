/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:29 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:14:30 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_dir(char *tmp)
{
	tmp = getcwd(NULL, 0);
	if (tmp)
	{
		printf("%s\n", tmp);
		free(tmp);
		g_return = 0;
	}
	else
	{
		ft_putstrendl_fd("Error Occured!", 1);
		g_return = 127;
	}
}
