/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:37:44 by iyapar            #+#    #+#             */
/*   Updated: 2022/04/22 13:37:51 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_matrix_create(t_game *game, char *file)
{
	int		i;
	int		j;
	int		fd;
	char	*area;

	fd = open(file, O_RDONLY);
	game->matris = (char **)malloc(sizeof(char *) * 8888);
	i = 0;
	j = 0;
	while (i < game->map_sizey)
	{
		j = 0;
		area = get_next_line(fd);
		game->matris[i] = (char *)malloc(sizeof(char *) * 8888);
		if (area == NULL)
			break ;
		while (j < game->map_sizex)
		{
			game->matris[i][j] = (char)area[j];
			j++;
		}
		game->matris[i][j] = '\0';
		i++;
	}
	close (fd);
}
