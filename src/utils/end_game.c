/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:47:46 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 14:04:10 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear(void)
{
	ft_printf("\033[2J\033[H");
	return ;
}

static void	print_stat(t_game *game)
{
	ft_printf("-- stats --\n");
	ft_printf("\n Movement : %d\n\n", game->player.move);
	return ;
}

void	game_over(t_game *game)
{
	(void)game;
	clear();
	ft_printf("\n\033[1;31m GAME OVER 💀\033[0m\n\n");
	print_stat(game);
	return ;
}

void	game_win(t_game *game)
{
	(void)game;
	clear();
	ft_printf("\033[32m YOU WIN 🎉\033[0m\n\n");
	print_stat(game);
	return ;
}
