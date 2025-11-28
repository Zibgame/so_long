# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 15:50:12 by zcadinot          #+#    #+#              #
#    Updated: 2025/11/28 14:47:36 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = clang
CFLAGS      = -Wall -Wextra -Werror -I. \
              -I./library/libft \
              -I./library/get_next_line \
              -I./library/mlx42/include
RM          = rm -f

LIBFT_DIR   = library/libft
GNL_DIR     = library/get_next_line
MLX42_DIR   = library/mlx42
PRINTF_DIR  = library/ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

LIBFT       = $(LIBFT_DIR)/libft.a
GNL         = $(GNL_DIR)/get_next_line.a
MLX42_LIB   = $(MLX42_DIR)/build/libmlx42.a

SRC_DIR     = src
OBJ_DIR     = obj

SRC         = main.c \
              src/parsing/check_arg.c \
              src/parsing/get_map.c \
              src/render/render_map.c \
              src/utils/map_size.c \
              src/utils/randint.c \
              src/parsing/check_ber.c \
              src/parsing/check_border.c \
              src/parsing/get_nb_collectible.c \
              src/utils/check_openable.c \
              src/utils/free_map.c \
              src/utils/check_collectible.c \
              src/utils/check_map_size.c \
              src/utils/dup_map.c \
              src/utils/check_monster.c \
              src/utils/check_exit.c \
              src/utils/end_game.c \
              src/utils/print_move.c \
              src/parsing/check_map_valid.c \
              src/render/display_player.c \
              src/render/update_tile.c \
              src/render/render_monster.c \
              src/render/draw_text.c \
              src/player/create_player.c \
              src/player/find_player.c \
              src/player/move_player.c \
              src/game/quit_game.c \
              src/game/start_game.c \
              src/game/check_path.c \
              src/game/flood_fill.c \
              src/input/handle_key.c \
              src/render/display_tile.c

OBJ         = $(SRC:%.c=$(OBJ_DIR)/%.o)

MLX42_FLAGS = -ldl -lglfw -pthread -lm
MLX42_INC   = -I$(MLX42_DIR)/include

$(NAME): $(LIBFT) $(GNL) $(PRINTF) $(MLX42_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(PRINTF) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)
	@echo "Success: $(NAME)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	@$(MAKE) -C $(GNL_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(MLX42_LIB):
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build -j4

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@echo "Dossier obj delete"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	@$(MAKE) -C $(GNL_DIR) fclean || true
	@echo "All Delete"

re: fclean $(NAME)

.PHONY: all clean fclean re
