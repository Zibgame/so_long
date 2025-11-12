/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:36:53 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 11:51:44 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->grid)
		free_map(game->grid);
	if (game->player.img)
		mlx_delete_image(game->mlx, game->player.img);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	exit(0);
}
