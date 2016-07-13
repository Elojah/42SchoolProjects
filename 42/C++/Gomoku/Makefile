# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/23 13:00:48 by hdezier           #+#    #+#              #
#    Updated: 2016/05/18 17:46:09 by erobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
TARGET = gomoku

#Directories
BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib

#Options
CC = clang++
SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = \
		main\
		GameManager\
		Rules\
		Board\
		Player\
		UserInterface\
		AudioManager\
		minmax\

#List interfaces here
INTERFACE = \

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))

#Flags
CFLAGS =-MMD -Wall -Wextra -Werror -O3 -std=c++11
LFLAGS =

#Libs
PWD = $(shell pwd)
ASFML = SFML-2.2-osx-clang-universal
DSFML = $(LIB_DIR)/sfml

LIB_LOCAL = \
			./$(DSFML)\

LIB_GLOBAL = \
			sfml-graphics\
			sfml-window\
			sfml-system\
			sfml-audio \

LIB_OTHER = \
			-rpath $(PWD)/$(DSFML)/lib/\

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))

#RULES
all : dirlib dirbin $(DSFML) $(BIN_DIR)/$(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET) $(BIN_DIR)
	$(RM) $(DSFML)

re : fclean all

$(DSFML):
	curl -L -O -# --progress-bar  http://www.sfml-dev.org/files/$(ASFML).tar.gz
	tar -xf $(ASFML).tar.gz
	mv $(ASFML) $(DSFML)
	cd $(DSFML)/Frameworks/ && ln -s ../extlibs/freetype.framework
	cd $(DSFML)/Frameworks/ && ln -s ../extlibs/sndfile.framework
	rm $(ASFML).tar.gz

dirbin:
	mkdir -p $(BIN_DIR)

dirlib:
	mkdir -p $(LIB_DIR)

.PHONY: all clean fclean re

.SILENT: dirlib dirbuild dirbin

#Build rule
$(BIN_DIR)/$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLNK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
	@ln -sf $(BIN_DIR)/$(TARGET) $(TARGET)

#Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCMP:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

-include $(DEP)
