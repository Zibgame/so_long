/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:01:08 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/18 11:14:40 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int mx, int my)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + mx;
	new_y = game->player.y + my;
	if (game->grid[new_y][new_x] == '1')
		return ;
	game->player.x = new_x;
	game->player.y = new_y;
	check_collectible(game);
	check_exit(game);
	game->player.img->instances[0].x = new_x * TILE_SIZE;
	game->player.img->instances[0].y = new_y * TILE_SIZE;
	return ;
}
