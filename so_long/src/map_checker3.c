/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:17:32 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/14 14:12:44 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	five_char(char c)
{
	int		i;
	char	arr[5];

	arr[0] = '0';
	arr[1] = '1';
	arr[2] = 'C';
	arr[3] = 'E';
	arr[4] = 'P';
	i = -1;
	while (++i < 5)
	{
		if (arr[i] == c)
			return (1);
	}
	return (0);
}

int	check_five_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!five_char(map[i][j]))
				return (0);
		}
	}
	return (1);
}
