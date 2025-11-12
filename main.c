/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:42:52 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 11:43:14 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_game game;

    if (check_arg(argc, argv))
        return (1);

    char **grid = get_map(argv[1]);
    if (!grid)
        return (1);

    if (!check_map_valid(grid))
    {
        ft_putendl_fd("Error\nInvalid map", 2);
        return (1);
    }

    game = start_game(argv[1]);
    mlx_loop(game.mlx);
    mlx_terminate(game.mlx);
    return (0);
}
