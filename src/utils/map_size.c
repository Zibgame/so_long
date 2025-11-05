/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:18:25 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 17:49:51 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*map_size(char **map)
{
	static int size[2];
	int y;
	int x;

	y = 0;	
	while(map[y])
		y++;
	if (y > (1080 / TILE_SIZE))
	{
		perror("\n ERROR: To Large Width Map \n \n");
		return(NULL);
	}
	x = 0;
	while(map[0][x])
		x++;
	if (x > (1920 / TILE_SIZE))
	{
		perror("\n ERROR: To Large Height Map \n \n");
		return(NULL);
	}
	size[0] = x; 
	size[1] = y; 
	return(size);
}
