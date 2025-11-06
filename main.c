/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:42:52 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/06 11:34:42 by zcadinot         ###   ########.fr       */
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
	{
		perror("\n ERROR \n \n ");
	}

	render_map(&game, game.map);

	game.player = create_player(&game);

	mlx_key_hook(game.mlx, handle_key, &game);
	mlx_close_hook(game.mlx, quit, &game);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);

	return (game);
}

int	main(int argc, char **argv)
{
	if (check_arg(argc, argv))
		return (1);
	start_game(argv[1]);
	return (0);
}
