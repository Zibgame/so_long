# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 15:50:12 by zcadinot          #+#    #+#              #
#    Updated: 2025/11/04 15:57:51 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 15:50:12 by zcadinot          #+#    #+#              #
#    Updated: 2025/11/04 17:45:00 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft
SRC_DIR		= src
OBJ_DIR		= obj

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= main.c

OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@
	@echo "Compiled: $<"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) ready!"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Objects cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "🧽 Full clean"

re: fclean all

.PHONY: all clean fclean re
