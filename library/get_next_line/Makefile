# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

NAME	= get_next_line.a
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I.
RM		= rm -f

SRC		= get_next_line.c get_next_line_utils.c
OBJ		= $(SRC:.c=.o)

# **************************************************************************** #
#                                   COMMANDS                                   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "\033[32m✅ Compilation réussie : $(NAME)\033[0m"

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "\033[33m🧹 get_next_line : objets supprimés\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31m🗑️  get_next_line : tout supprimé\033[0m"

re: fclean all

.PHONY: all clean fclean re

