/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:35:01 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 10:23:53 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return;
	if (keydata.key == MLX_KEY_ESCAPE)
		quit(game);
	else if ((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_K) || (keydata.key == MLX_KEY_UP))
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S || (keydata.key == MLX_KEY_J) || (keydata.key == MLX_KEY_DOWN))
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A || (keydata.key == MLX_KEY_H) || (keydata.key == MLX_KEY_LEFT))
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D || (keydata.key == MLX_KEY_L) || (keydata.key == MLX_KEY_RIGHT))
		move_player(game, 1, 0);
}
