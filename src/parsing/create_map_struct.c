/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:31:36 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/10 00:56:35 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	create_map_struct(char *path)
{
	t_map	map_struct;
	int		*size;

	map_struct.map_path = ft_strdup(path);
	if (!map_struct.map_path)
	{
		perror("Error\nFailed to allocate map_path");
		exit(EXIT_FAILURE);
	}
	map_struct.grid = get_map(path);
	if (!map_struct.grid)
	{
		perror("Error\nMap loading failed");
		exit(EXIT_FAILURE);
	}
	size = map_size(map_struct.grid);
	if (!size)
	{
		perror("Error\nInvalid map size");
		exit(EXIT_FAILURE);
	}
	map_struct.width = size[0];
	map_struct.height = size[1];
	return (map_struct);
}
