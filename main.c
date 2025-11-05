/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:42:52 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 14:33:53 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(0);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit(game);
}

int	start_game(t_game *game)
{
	game->mlx = mlx_init(800, 600, GAME_NAME, false);
	if (!game->mlx)
		return (1);
	mlx_key_hook(game->mlx, handle_key, game);
	mlx_close_hook(game->mlx, quit, game);
	display_tile(game,"assets/textures/Grass/Grass_23-128x128.png", 500, 100);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}

void display_tile(t_game *game,char *path, int x, int y)
{
	mlx_texture_t	*tex;
	mlx_image_t *img;

	tex = mlx_load_png("assets/textures/Tile/Tile_13-128x128.png");
	if (!tex)
	{
		perror("error chargement image");
		return ;
	}
	img = mlx_texture_to_image(game->mlx, tex);
	if (!img)
	{
		perror("error de convertion image to texture");
		return ;
	}
	if (mlx_image_to_window(game->mlx, img, x, y) < 0)
	{
		perror("error affichage image");
		return ;
	}
	mlx_delete_texture(tex);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_arg(argc, argv))
		return (1);
	ft_bzero(&game, sizeof(t_game));
	start_game(&game);
	return (0);
}
