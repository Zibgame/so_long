/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:02:09 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 13:08:15 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char **grid)
{
	t_pos	p;
	char	**copy;
	int		y;
	int		x;

	p = find_player(grid);
	copy = dup_map(grid);
	if (!copy)
		return (0);
	flood_fill(copy, p.x, p.y);
	y = -1;
	while (copy[++y])
	{
		x = -1;
		while (copy[y][++x])
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				free_map(copy);
				return (0);
			}
		}
	}
	free_map(copy);
	return (1);
}
