/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:28:16 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/18 16:28:18 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*display_player(t_game *game, char *sprite, int x, int y)
{
	mlx_image_t	*player_img;

	player_img = display_tile(game, sprite, x, y);
	if (!player_img)
	{
		perror("\n Erreur : impossible d'afficher le joueur.\n \n");
		return (NULL);
	}
	return (player_img);
}
