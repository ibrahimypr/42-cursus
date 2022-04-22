/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:42:26 by iyapar            #+#    #+#             */
/*   Updated: 2022/04/22 17:36:44 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_key_up(t_game *game)
{
	t_image	image;

	ft_collect_coin(game, -1, 0);
	if (game->matris[game->ny - 1][game->nx] != '1')
	{
		if (game->matris[game->ny - 1][game->nx]
		== 'E' && game->coin_count == 0)
			destroy_win(game);
		else
		{
			if (game->coin_count >= 0 && game->matris[game->ny - 1][game->nx]
			!= 'E' && game->ny--)
			{
				image.vars = game->vars;
				game->move_count += 1;
				game->hero.y -= 48;
				ft_image_change(game, image, 0, 48);
				printf(YELLOW"moved to the left count = %d \n",
					game->move_count);
			}
		}
	}
}

void	ft_key_down(t_game *game)
{
	t_image	image;

	ft_collect_coin(game, 1, 0);
	if (game->matris[game->ny + 1][game->nx] != '1')
	{
		if (game->matris[game->ny + 1][game->nx] == 'E' && game->coin_count
		== 0)
			destroy_win(game);
		else
		{
			if (game->coin_count >= 0 && game->matris[game->ny + 1][game->nx]
			!= 'E' && game->ny++)
			{
				image.vars = game->vars;
				game->move_count += 1;
				game->hero.y += 48;
				ft_image_change(game, image, 0, -48);
				printf(GREEN"moved to the left count = %d \n", game->move_count);
			}
		}
	}
}

void	ft_key_right(t_game *game)
{
	t_image	image;

	ft_collect_coin(game, 0, 1);
	if (game->matris[game->ny][game->nx + 1] != '1')
	{
		if (game->matris[game->ny][game->nx + 1] == 'E' && game->coin_count
		== 0)
			destroy_win(game);
		else
		{
			if (game->coin_count >= 0 && game->matris[game->ny][game->nx + 1]
			!= 'E' && game->nx++)
			{
				image.vars = game->vars;
				game->move_count += 1;
				game->hero.x += 48;
				ft_image_change(game, image, -48, 0);
				printf(BLUE"moved to the left count = %d \n", game->move_count);
			}
		}
	}
}

void	ft_key_left(t_game *game)
{
	t_image	image;

	ft_collect_coin(game, 0, -1);
	if (game->matris[game->ny][game->nx - 1] != '1')
	{
		if (game->matris[game->ny][game->nx - 1] == 'E' && game->coin_count
		== 0)
			destroy_win(game);
		else
		{
			if (game->coin_count >= 0 && game->matris[game->ny][game->nx - 1]
			!= 'E' && game->nx--)
			{
				image.vars = game->vars;
				game->move_count += 1;
				game->hero.x -= 48;
				ft_image_change(game, image, 48, 0);
				printf(RED"moved to the left count = %d \n", game->move_count);
			}
		}
	}	
}

int	ft_key_esc(t_game *game)
{
	t_image	image;

	image.vars = game->vars;
	mlx_destroy_image(game->vars.mlx, game->vars.win);
	free(game->matris);
	exit(0);
	return (0);
}
