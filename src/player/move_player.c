/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:01:08 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 11:54:04 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int mx, int my)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + mx;
	new_y = game->player.y + my;
	if (game->grid[new_y][new_x] == '1')
		return ;
	game->player.x = new_x;
	game->player.y = new_y;
	check_collectible(game);
	check_exit(game);
	check_monster(game);
	game->player.move++;
	print_move(game->player);
	draw_move(game, 10, 10);
	update_player_sprite(game, mx, my);
	game->player.img->instances[0].x = new_x * TILE_SIZE;
	game->player.img->instances[0].y = new_y * TILE_SIZE;
	return ;
}

static char	*draw_left(t_game *game)
{
	char	*sprite;

	if (game->player.bin == 0)
	{
		game->player.bin = 1;
		sprite = SPRITE_LEFT_1;
	}
	else
	{
		game->player.bin = 0;
		sprite = SPRITE_LEFT_2;
	}
	return (sprite);
}

static char	*draw_right(t_game *game)
{
	char	*sprite;

	if (game->player.bin == 0)
	{
		game->player.bin = 1;
		sprite = SPRITE_RIGHT_1;
	}
	else
	{
		game->player.bin = 0;
		sprite = SPRITE_RIGHT_2;
	}
	return (sprite);
}

void	update_player_sprite(t_game *game, int mx, int my)
{
	char	*sprite;

	if (mx == 1)
	{
		sprite = draw_right(game);
	}
	else if (mx == -1)
		sprite = draw_left(game);
	else if (my == -1)
		sprite = SPRITE_UP;
	else
		sprite = SPRITE_DOWN;
	mlx_delete_image(game->mlx, game->player.img);
	game->player.img = display_player(game,
			sprite,
			game->player.x,
			game->player.y);
}
