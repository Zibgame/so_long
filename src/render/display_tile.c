/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:00:47 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/06 09:52:43 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t *display_tile(t_game *game,char *path, int x, int y)
{
	mlx_texture_t	*tex;
	mlx_image_t *img;

	tex = mlx_load_png(path);
	if (!tex)
		perror("\n ERROR : Failed to Load the texture from path \n \n");
	img = mlx_texture_to_image(game->mlx, tex);
	if (!img)
		perror("\n ERROR :Failed to convert the image \n \n");
	if (mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE) < 0)
		perror("\n ERROR :Failed to show image \n \n");
	mlx_delete_texture(tex);
	return (img);
}
