/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:05:03 by iyapar            #+#    #+#             */
/*   Updated: 2022/06/29 15:05:04 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_struct *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
/*int main()
{
	t_struct *a;

	a = ft_lstnew("a");
	a->next = ft_lstnew("b");
	a->next->next = ft_lstnew("c");
	printf("%d\n",ft_lstsize(a));
	while (a)
	{
		printf("%s\n",a->value);
		a = a->next;
	}

}
*/