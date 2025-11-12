/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_collectible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:37:06 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 09:13:41 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_tile(char **grid, char c)
{
	int	nb;
	int	x;
	int	y;
	int	*size;

	x = 0;
	y = 0;
	nb = 0;
	size = map_size(grid);
	while (y < size[1])
	{
		while (x < size[0])
		{
			if (grid[x][y] == c)
				nb++;
			x++;
		}
		y++;
	}
	return (nb);
}
