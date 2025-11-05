/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:00:24 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 18:05:07 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*find_player(char **map)
{
	int		y;
	int		x;
	int		*pos[2];
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = x;
				pos[1] = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	pos[0] = -1;
	pos[1] = -1;
	return (pos);
}
