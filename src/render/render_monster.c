/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:46:08 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 14:46:30 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_monster(t_game *game, int x, int y)
{
	char	*monster;
	char	*tmp;
	char	*path;

	path = ft_itoa(ft_randint(3));
	if (!path)
		return ;
	tmp = ft_strjoin(path, ".png");
	free(path);
	if (!tmp)
		return ;
	monster = ft_strjoin(MONSTER, tmp);
	free(tmp);
	if (!monster)
		return ;
	display_tile(game, GROUND, x, y);
	display_tile(game, monster, x, y);
	free(monster);
}
