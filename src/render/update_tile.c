/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:56:47 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/18 11:13:16 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_tile(t_game *game, int x, int y)
{
	display_tile(game, GROUND, x, y);
	if (ft_randint(100) < GROUND_S)
		display_tile(game, FLOWER, x, y);
	if (game->player.x == x && game->player.y == y)
	{
		mlx_delete_image(game->mlx, game->player.img);
		game->player.img = display_player(game, SPRITE, x, y);
	}
}
