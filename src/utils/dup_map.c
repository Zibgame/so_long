/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:00:15 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 13:00:21 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(char **src)
{
	int		y;
	int		height;
	char	**copy;

	height = map_size(src)[1];
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (src[y])
	{
		copy[y] = ft_strdup(src[y]);
		if (!copy[y])
			return (free_map(copy), NULL);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}
