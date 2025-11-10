/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:39:27 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/10 00:57:29 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	start_game(char *map_path)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.map = create_map_struct(map_path);
	game.mlx = mlx_init(game.map.width * TILE_SIZE, game.map.height * TILE_SIZE, GAME_NAME, false);
	if (!game.mlx)
		perror("\n ERROR \n \n ");
	render_map(&game, game.map.grid);
	game.player = create_player(&game);
	mlx_key_hook(game.mlx, handle_key, &game);
	mlx_close_hook(game.mlx, quit, &game);
	return (game);
}

