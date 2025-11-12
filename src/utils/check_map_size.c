/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:57:23 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 10:12:23 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(char **grid)
{
	int	width;
	int	height;

	width = ft_strlen(grid[0]);
	height = 0;
	while (grid[height])
		height++;
	if (width > MAX_TILES_X || height > MAX_TILES_Y)
	{
		return (0);
	}
	return (1);
}
