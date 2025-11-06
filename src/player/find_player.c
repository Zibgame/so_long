/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:00:24 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/06 10:25:20 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos find_player(char *map[])
{
	int tile_x;
	int tile_y;
	t_pos pos;

	tile_y = 0;
	while(map[tile_y])
	{
		tile_x = 0;
		while(map[tile_y][tile_x])
		{
			if (map[tile_y][tile_x] == 'P')
			{
				pos.x = tile_x;
				pos.y = tile_y;
			}
			tile_x++;
		}
		tile_y++;
	}
	return (pos);
}
