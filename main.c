/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:42:52 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/07 23:49:21 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	if (check_arg(argc, argv))
		return (1);
	game = start_game(argv[1]);
	// flood_fill(&game, map_size(game.map), game.player.x, game.player.y);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}
