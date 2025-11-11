/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:18:25 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/11 22:06:30 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*map_size(char **map)
{
	static int	size[2];
	int			y;
	int			x;

	if (!map)
		return (NULL);
	y = 0;
	size[0] = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x > size[0])
			size[0] = x;
		y++;
	}
	size[1] = y;
	return (size);
}
