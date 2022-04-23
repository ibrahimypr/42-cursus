/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:48:40 by iyapar            #+#    #+#             */
/*   Updated: 2022/04/23 15:22:56 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_zone	ft_put_zone(char type)
{
	t_zone	map[7];
	int		i;

	i = 0;
	map[0] = (t_zone){'1', "./image/asteroid.xpm"};
	map[1] = (t_zone){'E', "./image/blackhole.xpm"};
	map[2] = (t_zone){'0', "./image/stars.xpm"};
	map[3] = (t_zone){'C', "./image/moon.xpm"};
	map[4] = (t_zone){'P', "./image/planet.xpm"};
	map[5] = (t_zone){' ', "./image/error.xpm"};
	map[6] = (t_zone){'B', "./image/black.xpm"};
	while (i < 7)
	{
		if (map[i].name == type)
		{
			return (map[i]);
		}
		i++;
	}
	return (map[5]);
}

void	ft_put_image(int x, int y, t_image image, char type)
{
	image.x = x;
	image.y = y;
	image.path = ft_put_zone(type).path;
	image.img = mlx_xpm_file_to_image(image.vars.mlx,
			image.path, &image.width, &image.height);
	mlx_put_image_to_window(image.vars.mlx, image.vars.win,
		image.img, image.x, image.y);
}

void	ft_image_change(t_game *game, t_image image, int x, int y)
{
	ft_put_image(game->hero.x + x, game->hero.y + y, image, '0');
	ft_put_image(game->hero.x, game->hero.y, image, 'P');
}

void	ft_collect_coin(t_game *game, int y, int x)
{
	if (game->matris[game->ny + y][game->nx + x] == 'C')
	{
		game->coin_count--;
		game->matris[game->ny + y][game->nx + x] = '0';
	}
}
