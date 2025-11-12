/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:36:53 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 11:50:11 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void quit(void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (!game || !game->mlx)
		return ;
	mlx_close_window(game->mlx);
}
