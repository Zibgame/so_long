/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:56:31 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 14:15:43 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_player player)
{
	clear();
	ft_putstr_fd("\n  ---- So Long ----\n", 1);
	ft_putstr_fd("\n Nombre de mouvement : ", 1);
	ft_putnbr_fd(player.move, 1);
}
