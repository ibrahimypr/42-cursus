/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:29:19 by iyapar            #+#    #+#             */
/*   Updated: 2022/04/22 17:38:44 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 13)
		ft_key_up(game);
	else if (keycode == 0)
		ft_key_left(game);
	else if (keycode == 1)
		ft_key_down(game);
	else if (keycode == 2)
		ft_key_right(game);
	else if (keycode == 53)
		ft_key_esc(game);
	return (0);
}

void	destroy_win(t_game *game)
{
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	printf(CYAN"@@@@@@@@ ---- SO LONG GAME OVER ---- @@@@@@@@ ");
	exit(0);
	free(game);
}

int	main(int ac, char *file[])
{
	t_game	game;

	ac = 2;
	game.map_sizex = ft_get_map_size_x(file[1]);
	game.map_sizey = ft_get_map_size_y(file[1]);
	ft_matrix_create(&game, file[1]);
	if (ft_map_control(&game) == 1)
	{
		game.vars.mlx = mlx_init();
		game.vars.win = mlx_new_window(game.vars.mlx, 1920, 1080, "s");
		mlx_key_hook(game.vars.win, ft_key_hook, &game);
		mlx_hook(game.vars.win, ON_DESTROY, 0, ft_key_esc, &game);
		game.move_count = 0;
		game.game_over = 1;
		game.hero.type = 'P';
		game.coin_count = ft_find_coin(file[1]);
		game.hero.x = ft_get_hero_cord_x(file[1]) * 48;
		game.hero.y = ft_get_hero_cord_y(file[1]) * 48;
		game.nx = ft_get_hero_cord_x(file[1]);
		game.ny = ft_get_hero_cord_y(file[1]);
		ft_map_create(game, file[1]);
		mlx_loop(game.vars.mlx);
	}
	else
		printf("error type:%s", game.error);
}
