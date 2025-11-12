/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:57:07 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 07:56:21 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_randint(int max)
{
	static unsigned long	seed;
	int						local;
	unsigned long			mix;

	if (max <= 0)
		max = 1;
	mix = (unsigned long)&local
		^ (unsigned long)&max
		^ (unsigned long)&ft_randint;
	seed += mix + 0x9e3779b97f4a7c15;
	return (seed % (unsigned long)max);
}
