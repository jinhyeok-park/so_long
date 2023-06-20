/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:11:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/20 13:15:15 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_game **game)
{
	mlx_hook((*game)->mlx_window, 2, 0, player_move, game);
	mlx_hook((*game)->mlx_window, 17, 0, close_window, game);
	img_load(game);
	draw_map((*game));
	mlx_loop((*game)->mlx);
}

void	img_load(t_game **game)
{
	int	img_width;
	int	img_height;

	(*game)->img_wall = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/wall.xpm", &img_width, &img_height);
	(*game)->img_portal = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/portal.xpm", &img_width, &img_height);
	(*game)->img_coin = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/coin.xpm", &img_width, &img_height);
	(*game)->img_player = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_right_open.xpm", &img_width, &img_height);
	(*game)->img_black = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/black.xpm", &img_width, &img_height);
}

int	player_move(int keycode, t_game **game)
{
	exit_53(keycode, game);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		to_black((*game)->player_position[0], \
		(*game)->player_position[1], (*game));
	if (keycode == 13)
	{
		move_position((*game)->player_position[0] - 1, \
		(*game)->player_position[1], game);
	}
	if (keycode == 1)
	{
		move_position((*game)->player_position[0] + 1, \
		(*game)->player_position[1], game);
	}
	if (keycode == 0)
	{
		move_position((*game)->player_position[0], \
		(*game)->player_position[1] - 1, game);
	}
	if (keycode == 2)
	{
		move_position((*game)->player_position[0], \
		(*game)->player_position[1] + 1, game);
	}
	return (0);
}

void	move_position(int x, int y, t_game **game)
{
	if ((*game)->map[x][y] != '1')
	{
		(*game)->player_position[0] = x;
		(*game)->player_position[1] = y;
		(*game)->steps++;
		ft_printf("%d\n", (*game)->steps);
	}
	if ((*game)->map[x][y] == 'C')
	{
		(*game)->collectable_coin--;
		(*game)->collected_coin++;
		(*game)->map[x][y] = '0';
	}
	if ((*game)->collectable_coin == 0 && (*game)->map[x][y] == 'E')
	{
		draw_img((*game)->player_position[1], \
		(*game)->player_position[0], (*game)->img_player, (*game));
		game_fin(game);
	}
	draw_img((*game)->player_position[1], \
	(*game)->player_position[0], (*game)->img_player, (*game));
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == '1')
				draw_img(j, i, game->img_wall, game);
			if (game->map[i][j] == 'E')
				draw_img(j, i, game->img_portal, game);
			if (game->map[i][j] == 'C')
				draw_img(j, i, game->img_coin, game);
			if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				draw_img(j, i, game->img_black, game);
		}
	}
	draw_img(game->player_position[1], \
	game->player_position[0], game->img_player, game);
}
