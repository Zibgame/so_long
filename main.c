/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:42:52 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 13:18:59 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (check_arg(argc, argv))
		return (1);
	if (!check_map_valid(argv[1]))
		return (1);
	start_game(&game, argv[1]);
	mlx_loop(game.mlx);

	if (game.grid) free_map(game.grid);
	if (game.player.img) mlx_delete_image(game.mlx, game.player.img);
	if (game.mlx) mlx_terminate(game.mlx);
	return (0);
}
