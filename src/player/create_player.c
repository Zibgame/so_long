/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:27:07 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 15:28:18 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	create_player(t_game *game)
{
	mlx_image_t	*find_img;
	t_player	player;
	t_pos		find_pos;

	find_pos = find_player(game->grid);
	player.x = find_pos.x;
	player.y = find_pos.y;
	find_img = display_player(game, SPRITE, player.x, player.y);
	player.img = find_img;
	return (player);
}
