/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:10:03 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 15:32:30 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_bottom(char **grid)
{
	int	*size;
	int	x;

	if (!grid || !grid[0])
		return (0);
	size = map_size(grid);
	if (!size)
		return (0);
	x = 0;
	while (x < size[0])
	{
		if (grid[0][x] != '1' || grid[size[1] - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_sides(char **grid)
{
	int	*size;
	int	y;

	if (!grid || !grid[0])
		return (0);
	size = map_size(grid);
	if (!size)
		return (0);
	y = 0;
	while (y < size[1])
	{
		if (grid[y][0] != '1' || grid[y][size[0] - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_border(char **grid)
{
	if (!check_top_bottom(grid))
	{
		ft_putendl_fd("Error\nMap border is open (top or bottom)", 2);
		return (0);
	}
	if (!check_sides(grid))
	{
		ft_putendl_fd("Error\nMap border is open (left or right)", 2);
		return (0);
	}
	return (1);
}
