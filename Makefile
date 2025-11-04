# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 15:50:12 by zcadinot          #+#    #+#              #
#    Updated: 2025/11/05 00:09:28 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Wno-cast-function-type -g

MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= main.c
OBJ			= $(SRC:.c=.o)


all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) ready!"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -I. -c $< -o $@
	@echo "Compiled: $<"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo "🧹 Objects cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "🧽 Full clean"

re: fclean all

.PHONY: all clean fclean re
