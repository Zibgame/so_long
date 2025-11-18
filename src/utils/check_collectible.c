/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:26:50 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 12:44:57 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectible(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;

	if (game->grid[y][x] == 'C')
	{
		game->grid[y][x] = '0';
		game->player.item++;
		game->nbitem--;

		update_tile(game,x,y);
		return (1);
	}
	return (0);
}

