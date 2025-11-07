/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:57:07 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/07 23:57:14 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int randint(int max)
{
    static unsigned long seed = 0;
    int local;
    unsigned long mix;

    if (max <= 0)
        max = 100;

    mix = (unsigned long)&local ^ (unsigned long)&max ^ (unsigned long)&randint;
    seed += mix + 0x9e3779b97f4a7c15;
    return (seed % (unsigned long)max);
}
