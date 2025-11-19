/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:35:01 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/18 11:33:25 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_move_keys(t_game *game, int key)
{
	if (key == MLX_KEY_W || key == MLX_KEY_K || key == MLX_KEY_UP)
		move_player(game, 0, -1);
	else if (key == MLX_KEY_S || key == MLX_KEY_J || key == MLX_KEY_DOWN)
		move_player(game, 0, 1);
	else if (key == MLX_KEY_A || key == MLX_KEY_H || key == MLX_KEY_LEFT)
		move_player(game, -1, 0);
	else if (key == MLX_KEY_D || key == MLX_KEY_L || key == MLX_KEY_RIGHT)
		move_player(game, 1, 0);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		quit(game);
	else
		handle_move_keys(game, keydata.key);
}
