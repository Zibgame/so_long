/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:44:22 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/07 23:38:10 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int render_map(t_game *game, char *map[])
{
	int tile_x;
	int tile_y;

	tile_y = 0;
	while(map[tile_y])
	{
		tile_x = 0;
		while(map[tile_y][tile_x])
		{
			if (map[tile_y][tile_x] == '0')
			{
				display_tile(game, GROUND, tile_x, tile_y);
				if (randint(100) > 90)
					display_tile(game, FLOWER, tile_x, tile_y);
			}
			else if (map[tile_y][tile_x] == '1')
				display_tile(game, WALL, tile_x, tile_y);
			else if (map[tile_y][tile_x] == 'C')
			{
				display_tile(game, GROUND, tile_x, tile_y);
				display_tile(game, COLLEC, tile_x, tile_y);
			}
			else if (map[tile_y][tile_x] == 'E')
				display_tile(game, EXIT, tile_x, tile_y);
			else if (map[tile_y][tile_x] == 'P')
			{
				display_tile(game, GROUND, tile_x, tile_y);
				display_player(game, START, tile_x, tile_y);
			}
			else
				display_tile(game, GLICHT, tile_x, tile_y);
			tile_x++;
		}
		tile_y++;
	}
	return (1);
}
