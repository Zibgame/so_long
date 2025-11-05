/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:42:52 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 17:44:07 by zcadinot         ###   ########.fr       */
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

int	start_game(t_game *game,char *map_path)
{
	char **map;

	int *mapsize;

	map = get_map(map_path);
	mapsize = map_size(map);
	game->mlx = mlx_init(mapsize[0] * TILE_SIZE, mapsize[1] * TILE_SIZE, GAME_NAME, false);
	if (!game->mlx)
		return (1);

	mlx_key_hook(game->mlx, handle_key, game);
	mlx_close_hook(game->mlx, quit, game);
	render_map(game,map);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_arg(argc, argv))
		return (1);
	ft_bzero(&game, sizeof(t_game));
	start_game(&game, argv[1]);
	return (0);
}
