/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:31:32 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 14:11:13 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_move(t_game *game, int x, int y)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(game->player.move);
	str = ft_strjoin("Moves: ", tmp);
	if (game->moves_label)
		mlx_delete_image(game->mlx, game->moves_label);
	game->moves_label = mlx_put_string(game->mlx, str, x, y);
	free(tmp);
	free(str);
}
