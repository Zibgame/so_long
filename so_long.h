/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:31:53 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/06 12:16:30 by zcadinot         ###   ########.fr       */
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
# include "MLX42/MLX42.h"

# define GAME_NAME "So Long"

# define TILE_SIZE 42
# define MAP_WIDTH 16
# define MAP_HEIGHT 16
# define WIN_WIDTH (MAP_WIDTH * TILE_SIZE)
# define WIN_HEIGHT (MAP_HEIGHT * TILE_SIZE)

# define GROUND "assets/textures/Grass/Grass_23-42x42.png"
# define WALL "assets/textures/Bricks/Bricks_16-42x42.png"
# define GLICHT "assets/textures/other/glicht.png"
# define COLLEC "assets/textures/food/Peach.png"
# define EXIT "assets/textures/other/END.png"
# define START "assets/textures/other/spwan.png"
# define SPRITE "assets/textures/player/idle/player_idle1.png"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	int			x;
	int			y;
	mlx_image_t	*img;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	char		**map;
	char		*map_path;
	t_player	player;
}	t_game;

/* ================= CORE ================= */
int				main(int argc, char **argv);
t_game			start_game(char *map_path);
void			quit(void *param);

/* ================= INPUT ================= */
void			handle_key(mlx_key_data_t keydata, void *param);

/* ================= MAP PARSING ================= */
int				check_arg(int argc, char *argv[]);
int				check_ber(char *name);
char			**get_map(char *path);
int				*map_size(char **map);

/* ================= PLAYER ================= */
t_pos			find_player(char **map);
t_player		create_player(t_game *game);
mlx_image_t		*display_player(t_game *game, char *sprite, int x, int y);
void move_player(t_game *game, int mx, int my);

/* ================= RENDER ================= */
int				render_map(t_game *game, char *map[]);
mlx_image_t		*display_tile(t_game *game, char *path, int x, int y);

#endif

