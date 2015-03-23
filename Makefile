# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 05:41:35 by bsautron          #+#    #+#              #
#    Updated: 2015/03/23 14:00:19 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fractol
SRC = main.c \
	  expose_hook.c \
	  key_hook.c \
	  \
	  ft_put_pixel_to_image.c
OBJ = $(SRC:%.c=obj/%.o)
CFLAGS = -Wextra -Wall -Werror
LIB = -L./libft -lft
LX11 = -framework OPENGL -framework AppKit -lmlx 

.PHONY: all libs clean fclean re

all: libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIB) $(LX11)
	@echo "\033[32mReady!\033[0m"

libs:
	make -C libft/
	make -C minilibx_macos/


obj/%.o: %.c includes/fractol.h
	@echo "\033[33m 	$<"
	@$(CC) -o $@ -I includes/ -c $< -Ofast -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
