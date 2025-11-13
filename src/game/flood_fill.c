/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:18:21 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 13:18:24 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **grid, int x, int y)
{
	int *size;

	size = map_size(grid); 
	if (x < 0 || y < 0 || x >= size[0] || y >= size[1])
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'F')
		return ;
	grid[y][x] = 'F';
	flood_fill(grid, x - 1, y);
	flood_fill(grid, x + 1, y);
	flood_fill(grid, x, y - 1);
	flood_fill(grid, x, y + 1);
}
