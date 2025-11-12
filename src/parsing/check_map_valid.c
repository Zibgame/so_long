/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:06:37 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 13:20:09 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_valid(char *path)
{
	char **grid;

	grid = get_map(path);
	if (!check_border(grid))
	{
		return (0);
	}
	if ((get_nb_tile(grid, 'C') < 1) || (get_nb_tile(grid, 'E')  != 1) || (get_nb_tile(grid, 'P')  != 1))
		return (0);
	if (!check_map_size(grid))
		return (0);
	if (!check_path(grid))
		return (0);
	return (1);
}

