#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/04/10 14:30:29 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = gui-ncurses.so
FILES = GUINCurses.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.cpp=objs/%.o)
INCS = $(SRCS:srcs/%.cpp=incs/%.hpp)
TMPS = $(SRCS:.cpp=.cpp~) $(INCS:.hpp=.hpp~) Makefile~
CC = g++
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincs/ -I../game/incs/
LFLAGS = -lncurses -ltermcap

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -shared -fPIC -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.cpp
	$(CC) $(CFLAGS) -Iinc $(IFLAGS) -o $@ -c $^

objs_dir:
	mkdir -p objs

clean:
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
