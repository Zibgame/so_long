/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:06:37 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/13 07:55:30 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	check_content(char **grid)
{
	if (get_nb_tile(grid, 'C') < 1
		|| get_nb_tile(grid, 'E') != 1
		|| get_nb_tile(grid, 'P') != 1)
	{
		ft_printf("Error\nmap must contain exactly 1 player, ");
		ft_printf("at least 1 collectible and 1 exit\n");
		return (0);
	}
	return (1);
}

static int	check_size_validity(char **grid)
{
	if (!check_map_size(grid))
	{
		ft_printf("Error\nmap to big\n");
		return (0);
	}
	return (1);
}

static int	check_path_validity(char **grid)
{
	if (!check_path(grid))
	{
		ft_printf("Error\nCant Open the map\n");
		return (0);
	}
	return (1);
}

int	check_map_valid(char *path)
{
	char	**grid;

	grid = get_map(path);
	if (!grid)
		return (0);
	if (!check_border(grid)
		|| !check_content(grid)
		|| !check_size_validity(grid)
		|| !check_path_validity(grid))
	{
		free_map(grid);
		return (0);
	}
	free_map(grid);
	return (1);
}
