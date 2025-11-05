/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:31:53 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/04 23:58:36 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "library/libft/libft.h"
# include "library/get_next_line/get_next_line.h"
# include "library/ft_printf/ft_printf.h"
# include "library/minilibx-linux/mlx.h"

# define KEY_ESC 65307
# define GAME_NAME "So Long"
# define KEY_W   119
# define KEY_A   97
# define KEY_S   115
# define KEY_D   100

typedef struct s_game
{
	void	*mlx;
	void	*win; 
}	t_game;

int	quit(void *param);

int handle_key(int keycode, void *param);

int	check_arg(int argc, char *argv[]);

int start_game(t_game *game);

int	main(int argc, char **argv);

#endif

