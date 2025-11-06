/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:30:33 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/06 09:47:14 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 4)
		return (1);
	if (ft_strncmp(name + len - 4, ".ber", 4) == 0)
		return (0);
	return (1);
}
