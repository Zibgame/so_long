# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 11:29:35 by zcadinot          #+#    #+#              #
#    Updated: 2025/10/28 23:40:00 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.
AR		= ar rcs
RM		= rm -f

SRC		= src/ft_printf.c \
		  src/parser.c \
		  src/utils.c \
		  ft_putchar_fd.c \
		  ft_putnbr_fd.c \
		  ft_putunbr_fd.c \
		  ft_strlen.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) a.out

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -I. src/main.c $(NAME) -o a.out

.PHONY: all clean fclean re test
