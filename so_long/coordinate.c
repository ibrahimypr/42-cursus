/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:08:53 by iyapar            #+#    #+#             */
/*   Updated: 2022/04/22 13:10:34 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_get_hero_cord_x(char *file)
{
	int		byt;
	char	l;
	int		syc;
	int		fd;

	syc = 0;
	byt = 1;
	fd = open(file, O_RDONLY);
	while (byt != 0)
	{
		byt = read(fd, &l, 1);
		if (l == 'P')
			break ;
		syc++;
		if (l == '\n')
			syc = 0;
	}
	close (fd);
	return (syc);
}

int	ft_get_hero_cord_y(char *file)
{
	int		byt;
	char	l;
	int		syc;
	int		fd;

	syc = 0;
	byt = 1;
	fd = open(file, O_RDONLY);
	while (byt != 0)
	{
		byt = read(fd, &l, 1);
		if (l == '\n')
			syc++;
		if (l == 'P')
			break ;
	}
	close (fd);
	return (syc);
}

int	ft_find_coin(char *file)
{
	int		fd;
	int		count;
	int		buff;
	char	x;

	fd = open(file, O_RDONLY);
	count = 0;
	buff = 1;
	x = 'x';
	while (buff == 1 && x != '\0')
	{
		buff = read(fd, &x, 1);
		if (x == 'C')
			count++;
	}
	close (fd);
	return (count);
}
