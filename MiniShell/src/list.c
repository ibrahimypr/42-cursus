/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:21 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:14:22 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	**add_list(char **str, t_list **mini)
{
	int		i;
	char	*temp;
	t_list	*temp2;

	i = 0;
	while (str[i])
	{
		temp = ft_strtrim(str[i], " ");
		temp2 = ft_lstnew(temp);
		ft_lstadd_back(mini, temp2);
		temp = NULL;
		temp2 = NULL;
		i++;
	}
	free (temp);
	free (temp2);
	return (mini);
}
