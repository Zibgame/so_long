/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:42:52 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/04 16:18:42 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"

int main(void)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    if (!mlx)
    {
        return (1);
    }
    win = mlx_new_window(mlx, 800, 600,"So Long");
    if (!win)
    {
        return (1);
    }
    mlx_loop(mlx);
    return (0);
}

