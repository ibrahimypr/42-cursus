/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:16:13 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:16:14 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(char *str)
{
	t_list	*root;

	root = (t_list *)malloc(sizeof(*root));
	if (root == NULL)
		return (NULL);
	root -> data = str;
	root -> next = NULL;
	return (root);
}
