/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:31:53 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 11:44:58 by zcadinot         ###   ########.fr       */
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

# include "MLX42/MLX42.h"
# include <stdio.h>

# define GAME_NAME "So Long"

# define TILE_SIZE 42
# define MAX_WIN_WIDTH 1920
# define MAX_WIN_HEIGHT 1080
# define MAX_TILES_X 44
# define MAX_TILES_Y 24

# define GROUND "assets/textures/Grass/Grass01.png"
# define GROUND_S 5
# define WALL "assets/textures/Bricks/Bricks_17-42x42.png"
# define GLICHT "assets/textures/other/glicht.png"
# define COLLEC "assets/textures/food/Peach.png"
# define EXIT "assets/textures/other/END.png"
# define START "assets/textures/other/spwan.png"
# define FLOWER "assets/textures/Flowers/flower.png"
# define MONSTER "assets/textures/monster/idle/monster_idle1.png"
# define SPRITE_UP "assets/textures/player/idle/player_idle1.png"
# define SPRITE "assets/textures/player/idle/player_idle1.png"
# define SPRITE_DOWN "assets/textures/player/idle/player_idle2.png"
# define SPRITE_LEFT "assets/textures/player/idle/player_idle3.png"
# define SPRITE_RIGHT_1 "assets/textures/player/idle/player_idle4.png"
# define SPRITE_RIGHT_2 "assets/textures/player/idle/player_idle4_2.png"

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
	int			item;
	int			move;
	int			bin;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*moves_label;
	char		**grid;
	char		*path;
	t_player	player;
	int			nbitem;
}	t_game;

/* ================= CORE ================= */
int				main(int argc, char **argv);
void			start_game(t_game *game, char *map_path);
void			quit(void *param);
void			flood_fill(char **grid, int x, int y);
void			free_map(char **map);
unsigned long	ft_cpu_cycles(void);
int				ft_randint(int max);
int				check_exit(t_game *game);
char			**dup_map(char **src);
int				check_path(char **grid);

/* ================= INPUT ================= */
void			handle_key(mlx_key_data_t keydata, void *param);

/* ================= MAP PARSING ================= */
int				check_arg(int argc, char *argv[]);
int				check_ber(char *name);
char			**get_map(char *path);
int				*map_size(char **map);
int				check_openable(char *map_path);
int				check_top_bottom(char **grid);
int				check_sides(char **grid);
int				check_border(char **grid);
int				check_map_valid(char *path);
int				get_nb_tile(char **grid, char c);

/* ================= PLAYER ================= */
t_pos			find_player(char **map);
t_player		create_player(t_game *game);
mlx_image_t		*display_player(t_game *game, char *sprite, int x, int y);
void			move_player(t_game *game, int mx, int my);
int				check_collectible(t_game *game);
int				check_monster(t_game *game);
void			update_player_sprite(t_game *game, int mx, int my);

/* ================= RENDER ================= */
void			draw_tile(t_game *game, char **map, int x, int y);
int				render_map(t_game *game, char *map[]);
mlx_image_t		*display_tile(t_game *game, char *path, int x, int y);
void			update_tile(t_game *game, int x, int y);
void			print_move(t_player player);
void			draw_move(t_game *game, int x, int y);

/* == OTHER == */
int				check_map_size(char **grid);

#endif
