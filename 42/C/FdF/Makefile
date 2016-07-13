#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/15 10:25:21 by hdezier           #+#    #+#              #
#    Updated: 2014/02/15 10:25:21 by hdezier          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
FILES = main.c calculus.c draw_lib.c main_loop.c calc_grid.c
SRC = $(addprefix src/, $(FILES))
OBJ = $(SRC:src/%.c=obj/%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L./libft/ -L/usr/X11R6/lib -lX11 -lXext\
		-framework OpenGL -framework AppKit -L./minilibx_macos/ -lm -lft -lmlx
INC = -Iinclude/ -I./libft -I./minilibx_macos -I/usr/X11R6/include

.PHONY: all objs_dir clean fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $^

objs_dir:
	mkdir -p obj

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ) $(TMPS)
	/bin/rm -rf obj

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
