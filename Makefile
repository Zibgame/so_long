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
			  -I./library/minilibx-linux
RM			= rm -f

# Dossiers
LIBFT_DIR	= library/libft
GNL_DIR		= library/get_next_line
MLX_DIR		= library/minilibx-linux

# Fichiers librairies
LIBFT		= $(LIBFT_DIR)/libft.a
GNL			= $(GNL_DIR)/get_next_line.a
MLX			= $(MLX_DIR)/libmlx.a

SRC_DIR		= src
OBJ_DIR		= obj

# Sources principales
SRC			= main.c \
			  src/parsing/check_arg.c \
			  src/parsing/get_map.c

OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                   COMMANDES                                  #
# **************************************************************************** #

$(NAME): $(LIBFT) $(GNL) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(MLX) -lX11 -lXext -lm -o $(NAME)
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

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# **************************************************************************** #
#                                   CLEAN / RE                                 #
# **************************************************************************** #

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[33m🧹 Dossier obj supprimé\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	@$(MAKE) -C $(GNL_DIR) fclean || true
	@echo "\033[31m🗑️  Tout supprimé\033[0m"

re: fclean $(NAME)

.PHONY: all clean fclean re

