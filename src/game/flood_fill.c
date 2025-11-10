/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:08:12 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/10 01:58:25 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int size[2], int x, int y)
{
	char	**map;

	map = game->grid;

	if (x < 0 || y < 0 || x >= size[0] || y >= size[1])
		return ;

	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;

	map[y][x] = 'F';

	display_tile(game, GLICHT, x, y);

	flood_fill(game, size, x - 1, y); // gauche
	flood_fill(game, size, x + 1, y); // droite
	flood_fill(game, size, x, y - 1); // haut
	flood_fill(game, size, x, y + 1); // bas
}

