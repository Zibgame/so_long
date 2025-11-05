/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:44:22 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 16:01:29 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int render_map(t_game *game, char *map[])
{
	int tile_x;
	int tile_y;
	
	tile_x = 0;
	tile_y = 0;
	while(map[0][tile_x])
	{
		display_tile(game, GROUND, tile_x, tile_y);
		tile_x++;
	}
	return (1);
}
