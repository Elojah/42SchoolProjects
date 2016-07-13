#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/04/10 14:30:17 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = gui-sfml.so
FILES = GUISFML.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.cpp=objs/%.o)
INCS = $(SRCS:srcs/%.cpp=incs/%.hpp)
TMPS = $(SRCS:.cpp=.cpp~) $(INCS:.hpp=.hpp~) Makefile~
PWD = $(shell pwd)
ASFML = SFML-2.2-osx-clang-universal
DSFML = ../SFML
CC = g++
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincs/ -I../game/incs/ -I$(DSFML)/include/
LFLAGS = -L$(DSFML)/lib -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(DSFML) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -dynamiclib -rpath $(PWD)/$(DSFML)/lib/ -o $(NAME) $(OBJS) \
	$(LFLAGS)

objs/%.o : srcs/%.cpp
	$(CC) $(CFLAGS) -Iinc $(IFLAGS) -o $@ -c $^

objs_dir:
	mkdir -p objs

$(DSFML):
	curl -L -O -# --progress-bar  http://www.sfml-dev.org/files/$(ASFML).tar.gz
	tar -xf $(ASFML).tar.gz
	mv $(ASFML) $(DSFML)
	cd $(DSFML)/Frameworks/ && ln -s ../extlibs/freetype.framework
	cd $(DSFML)/Frameworks/ && ln -s ../extlibs/sndfile.framework
	rm $(ASFML).tar.gz

clean:
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf $(DSFML)

re: fclean all
