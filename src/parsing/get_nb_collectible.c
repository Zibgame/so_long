/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_collectible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:37:06 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 09:19:58 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_tile(char **grid, char c)
{
	int	nb;
	int	x;
	int	y;
	int	*size;

	nb = 0;
	size = map_size(grid);
	y = 0;
	while (y < size[1])
	{
		x = 0;
		while (x < size[0])
		{
			if (grid[y][x] == c)
				nb++;
			x++;
		}
		y++;
	}
	return (nb);
}

