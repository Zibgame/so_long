/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:10:03 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/10 00:55:30 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_bottom(t_game game)
{
	int	x;

	x = 0;
	while (x < game.map.width)
	{
		if (game.map.grid[0][x] != '1'
			|| game.map.grid[game.map.height - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_sides(t_game game)
{
	int	y;

	y = 0;
	while (y < game.map.height)
	{
		if (game.map.grid[y][0] != '1'
			|| game.map.grid[y][game.map.width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_border(t_game game)
{
	if (!check_top_bottom(game))
	{
		ft_putendl_fd("Error\nMap border is open (top or bottom)", 2);
		return (0);
	}
	if (!check_sides(game))
	{
		ft_putendl_fd("Error\nMap border is open (left or right)", 2);
		return (0);
	}
	return (1);
}

