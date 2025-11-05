/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:00:47 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 15:01:17 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t *display_tile(t_game *game,char *path, int x, int y)
{
	mlx_texture_t	*tex;
	mlx_image_t *img;

	tex = mlx_load_png(path);
	if (!tex)
	{
		perror("error chargement image");
	}
	img = mlx_texture_to_image(game->mlx, tex);
	if (!img)
	{
		perror("error de convertion image to texture");
	}
	if (mlx_image_to_window(game->mlx, img, x, y) < 0)
	{
		perror("error affichage image");
	}
	mlx_delete_texture(tex);
	return (img);
}
