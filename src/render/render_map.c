/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:44:22 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 11:26:28 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, char **map, int x, int y)
{
	char	c;

	c = map[y][x];
	if (c == '0')
	{
		display_tile(game, GROUND, x, y);
		if (ft_randint(100) < GROUND_S)
			display_tile(game, FLOWER, x, y);
	}
	else if (c == '1')
		display_tile(game, WALL, x, y);
	else if (c == 'C')
	{
		display_tile(game, GROUND, x, y);
		display_tile(game, COLLEC, x, y);
	}
	else if (c == 'E')
		display_tile(game, EXIT, x, y);
	else if (c == 'P')
	{
		display_tile(game, GROUND, x, y);
		display_player(game, START, x, y);
	}
	else
		display_tile(game, GLICHT, x, y);
}

int	render_map(t_game *game, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			draw_tile(game, map, x, y);
	}
	return (1);
}
