/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:39:27 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/06 12:40:24 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	start_game(char *map_path)
{
	t_game	game;
	int		*mapsize;

	ft_bzero(&game, sizeof(t_game));
	game.map_path = map_path;
	game.map = get_map(map_path);
	mapsize = map_size(game.map);
	game.mlx = mlx_init(mapsize[0] * TILE_SIZE, mapsize[1] * TILE_SIZE,
			GAME_NAME, false);
	if (!game.mlx)
		perror("\n ERROR \n \n ");
	render_map(&game, game.map);
	game.player = create_player(&game);
	mlx_key_hook(game.mlx, handle_key, &game);
	mlx_close_hook(game.mlx, quit, &game);
	return (game);
}

