/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:07:16 by iyapar            #+#    #+#             */
/*   Updated: 2022/06/30 17:03:37 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <limits.h>

int	*ft_to_arr(char **s, int counter)
{
	int	*my_arr;
	int	i;
	int	k;

	i = 1;
	k = 0;
	my_arr = (int *)malloc(sizeof(int) * counter);
	while (s[i])
	{
		my_arr[k] = ft_atoi(s[i]);
		k++;
		i++;
	}
	return (my_arr);
}

int	ft_dup_check(char **s, int counter)
{
	int	i;
	int	j;
	int	*my_arr;

	i = 0;
	my_arr = ft_to_arr(s, counter);
	while (i < counter)
	{
		j = i + 1;
		while (j < counter)
		{
			if (my_arr[i] == my_arr[j])
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(my_arr);
	return (1);
}

void	ft_max_min_check(char *a)
{
	if ((ps_atoll(a) <= INT_MAX && ps_atoll(a) >= INT_MIN))
		return ;
	write(1, "Error\n", 6);
	exit (0);
}

int	ft_arg_check(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		ft_max_min_check(s[i]);
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == '-' || s[i][j] == '+')
				j++;
			if (!ft_isdigit(s[i][j]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	if (ft_dup_check(s, i - 1) == 0)
		return (0);
	return (1);
}

int	ft_is_sorted(t_struct *stackA)
{
	while (stackA->next)
	{
		if (stackA->value > stackA->next->value)
			return (0);
		stackA = stackA->next;
	}
	return (1);
}
