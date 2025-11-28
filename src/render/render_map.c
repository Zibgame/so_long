/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:44:22 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 10:45:36 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_ground(t_game *game, int x, int y)
{
	display_tile(game, GROUND, x, y);
	if (ft_randint(100) < GROUND_S)
		display_tile(game, FLOWER, x, y);
}

static void	draw_collectible(t_game *game, int x, int y)
{
	display_tile(game, GROUND, x, y);
	display_tile(game, COLLEC, x, y);
}

static void	draw_player_spawn(t_game *game, int x, int y)
{
	display_tile(game, GROUND, x, y);
}

void	draw_tile(t_game *game, char **map, int x, int y)
{
	char	c;

	c = map[y][x];
	if (c == '0')
		draw_ground(game, x, y);
	else if (c == '1')
		display_tile(game, WALL, x, y);
	else if (c == 'C')
		draw_collectible(game, x, y);
	else if (c == 'E')
		display_tile(game, EXIT, x, y);
	else if (c == 'P')
		draw_player_spawn(game, x, y);
	else if (c == 'M')
	{
		display_tile(game, GROUND, x, y);
		display_player(game, MONSTER, x, y);
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
