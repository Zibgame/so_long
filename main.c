/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:42:52 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/04 23:33:45 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	quit(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		quit(game);
	return (0);
}

int	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, 800, 600, GAME_NAME);
	if (!game->win)
	{
		free(game->mlx);
		return (1);
	}
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, quit, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc,char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	start_game(&game);
	return (0);
}

