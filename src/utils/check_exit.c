/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:31:12 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 11:36:13 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	check_exit(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;

	if (game->grid[y][x] == 'E')
	{
		game->grid[y][x] = '0';
		game->player.item++;

		update_tile(game,x,y);
		quit(&game);
		return (1);
	}
	return (0);
}

