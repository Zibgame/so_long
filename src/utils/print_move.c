/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:56:31 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/18 14:06:10 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_player player)
{
	write(1, "\r\033[K", 4);
	ft_putstr_fd("Nombre de mouvement : ", 1);
	ft_putnbr_fd(player.move, 1);
}
