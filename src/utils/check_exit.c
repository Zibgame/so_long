/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:31:12 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 12:06:46 by zcadinot         ###   ########.fr       */
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
		if (game->player.item == game->nbitem)
		{
			game->grid[y][x] = '0';
			quit(game);
		}
		return (1);
	}
	return (0);
}

