/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:46:01 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/20 12:44:53 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
	int		total_len;
	int		steps;
	int		collectable_coin;
	int		collected_coin;
	int		accessible_coin;
	int		is_accessible;
	void	*mlx;
	void	*mlx_window;
	int		player_position[2];
	void	*img_wall;
	void	*img_black;
	void	*img_coin;
	void	*img_portal;
	void	*img_player;
}	t_game;

//map_checker.c
int		count_coin(t_game **game, char **map);
int		is_surrounded(t_game **game, char **map);
int		line_size_check(t_game **game, char **map);
int		get_portal_pos(t_game **game, char **map);
int		get_player_pos(t_game **game, char **map);
//map_checker2.c
char	**map_checker(char **av, t_game **game, int fd);
char	**map_checker_2(char **map, t_game **game);
char	**map_checker_3(char **map, t_game **game);
int		portal_accessible(char **map, t_game **game);
//map_checker3.c
int		five_char(char c);
int		check_five_char(char **map);
//so_long_utils.c
void	draw_img(int y, int x, void *img, t_game *game);
char	*ft_strjoin_custom(char *s1, char *s2);
void	game_fin(t_game **game);
int		close_window(t_game **game);
void	to_black(int x, int y, t_game *game);
//so_long.c
void	game_start(t_game **game);
void	img_load(t_game **game);
int		player_move(int keycode, t_game **game);
void	move_position(int x, int y, t_game **game);
void	draw_map(t_game *game);
//init.c
void	map_init1(t_game **game);
void	map_init_size(t_game **game);
void	init_map(char **map, int height, int width);
//free.c
void	free_game(t_game **game);
void	free_map(char **map);
//error.c
void	error_msg(int num);
void	to_black(int x, int y, t_game *game);
//dfs
void	dfs(int x, int y, char **visited, t_game **game);
//exit.c
void	exit_53(int keycode, t_game **game);
void	checker(t_game **game, char **av);
int		type_checker(char *s);

#endif