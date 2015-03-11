# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 05:41:35 by bsautron          #+#    #+#              #
#    Updated: 2015/03/11 18:19:16 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fractol
SRC = main.c
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wextra -Wall -Werror
LIB = -L./libft -lft
LX11 = -L/usr/X11/lib -lmlx -lXext -lX11

all: libs $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31m"
	@$(CC) -o $@ $^ $(LIB) $(LIX11)
	@echo "\033[37m"

libs:
	make -C libft/

%.o: %.c
	@echo "\033[33m   $^"
	@$(CC) $(CFLAGS) -I includes/ -c $^ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
