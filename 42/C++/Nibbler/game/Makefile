#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/04/10 14:43:46 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = nibbler
FILES = Game.cpp Time.cpp Editor.cpp main.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.cpp=objs/%.o)
INCS = $(SRCS:srcs/%.cpp=incs/%.hpp) incs/IGUINibbler.hpp
TMPS = $(SRCS:.cpp=.cpp~) $(INCS:.hpp=.hpp~) Makefile~
CC = g++
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincs/
LFLAGS = -lncurses -ltermcap

.PHONY: all clean objs_dir child fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

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
