/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:39:27 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 14:13:46 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game, char *map_path)
{
	ft_bzero(game, sizeof(t_game));
	game->grid = get_map(map_path);
	game->path = map_path;
	game->mlx = mlx_init(
			map_size(game->grid)[0] * TILE_SIZE,
			map_size(game->grid)[1] * TILE_SIZE,
			GAME_NAME,
			false);
	if (!game->mlx)
	{
		perror("\n ERROR \n \n ");
		exit(EXIT_FAILURE);
	}
	clear();
	print_move(game->player);
	render_map(game, game->grid);
	game->player = create_player(game);
	game->nbitem = get_nb_tile(game->grid, 'C');
	mlx_key_hook(game->mlx, handle_key, game);
	mlx_close_hook(game->mlx, quit, game);
}
