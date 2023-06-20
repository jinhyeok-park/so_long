/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:09:33 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/14 14:18:43 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_53(int keycode, t_game **game)
{
	if (keycode == 53)
	{
		mlx_destroy_window((*game)->mlx, (*game)->mlx_window);
		free_game(game);
		exit(0);
	}
}
