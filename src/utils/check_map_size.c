/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:57:23 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 10:03:03 by zcadinot         ###   ########.fr       */
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

	if (width >  WIN_WIDTH || height > WIN_HEIGHT) 
	{
		return (0);
	}
	return (1);
}
