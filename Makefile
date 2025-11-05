# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 15:50:12 by zcadinot          #+#    #+#              #
#    Updated: 2025/11/05 11:58:00 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

NAME		= so_long
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -I. \
			  -I./library/libft \
			  -I./library/get_next_line \
			  -I./library/mlx42/include
RM			= rm -f

# Dossiers
LIBFT_DIR	= library/libft
GNL_DIR		= library/get_next_line
MLX42_DIR	= library/mlx42

# Fichiers librairies
LIBFT		= $(LIBFT_DIR)/libft.a
GNL			= $(GNL_DIR)/get_next_line.a
MLX42_LIB	= $(MLX42_DIR)/build/libmlx42.a

SRC_DIR		= src
OBJ_DIR		= obj

# Sources principales
SRC			= main.c \
			  src/parsing/check_arg.c \
			  src/parsing/get_map.c \
			  src/render/render_map.c \
			  src/render/display_tile.c

OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

# Flags spécifiques à MLX42
MLX42_FLAGS	= -ldl -lglfw -pthread -lm
MLX42_INC	= -I$(MLX42_DIR)/include

# **************************************************************************** #
#                                   COMMANDES                                  #
# **************************************************************************** #

$(NAME): $(LIBFT) $(GNL) $(MLX42_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)
	@echo "\033[32m✅ Compilation réussie : $(NAME)\033[0m"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[90mCompilé : $<\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# **************************************************************************** #
#                                   LIBRARIES                                  #
# **************************************************************************** #

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	@$(MAKE) -C $(GNL_DIR)

$(MLX42_LIB):
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build -j4

# **************************************************************************** #
#                                   CLEAN / RE                                 #
# **************************************************************************** #

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@echo "\033[33m🧹 Dossier obj supprimé\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	@$(MAKE) -C $(GNL_DIR) fclean || true
	@echo "\033[31m🗑️  Tout supprimé\033[0m"

re: fclean $(NAME)

.PHONY: all clean fclean re

