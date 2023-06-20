/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:07:32 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/14 12:37:51 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game **game)
{
	free_map((*game)->map);
	free((*game)->img_wall);
	free((*game)->img_black);
	free((*game)->img_coin);
	free((*game)->img_portal);
	free((*game)->img_player);
	free((*game));
}

void	free_map(char **map)
{
	int	i;

	if (map)
	{
		i = -1;
		while (map[++i])
			free(map[i]);
		free(map);
	}
}
