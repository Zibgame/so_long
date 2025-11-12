/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:06:37 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 09:10:34 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_valid(char **grid)
{
	if (!check_border(grid))
	{
		return (0);
	}
	if ((get_nb_tile(grid, 'C') < 1))
		return (0);
	return (1);
}

