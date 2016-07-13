#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 17:24:53 by erobert           #+#    #+#              #
#    Updated: 2015/03/01 18:48:39 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = game_2048
FILES = ft_signal.c ft_play.c ft_display_grid.c ft_game_loop.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ incs/2048.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./libft/ -lft -lncurses -ltermcap

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.c
	$(CC) $(CFLAGS) -Iinc -I./incs -o $@ -c $^

objs_dir:
	mkdir -p objs

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
