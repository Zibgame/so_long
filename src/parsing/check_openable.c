/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_openable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:25:42 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/18 15:10:00 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_openable(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\ncannot open map file\n");
		exit(EXIT_FAILURE);
	}
	close(fd)
	return (0);
}
