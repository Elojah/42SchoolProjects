# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leeios <leeios@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/12 13:51:08 by leeios            #+#    #+#              #
#    Updated: 2015/09/06 19:04:14 by leeios           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = runner

#Directories
BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR =

#Options
CC = clang++-3.6
SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = main\
				mods/ClassMod\
					mods/MemberMod\
				commands/StandardCmd\
					commands/InterfaceCmd\
				ncurse/Window\
					ncurse/Menu\
				screens/Project\
					screens/Boot\
				utils/FtFile\
					utils/FtStr\
				json/jsoncpp

#List interfaces here
INTERFACE = \

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))

#Flags
CFLAGS = -Wall -Wextra -Werror -O3 -std=c++11
LFLAGS =

#Libs
LIB_LOCAL = \

LIB_GLOBAL = \
							ncurses\
							menu\

LIB_OTHER = \

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))

#RULES
all : dirbin $(BIN_DIR)/$(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET) $(BIN_DIR)

re : fclean all

dirbin:
	mkdir -p $(BIN_DIR)

.PHONY: all clean fclean re

.SILENT: dirlib dirbuild dirbin

#Build rule
$(BIN_DIR)/$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLINK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
	@ln -sf $(BIN_DIR)/$(TARGET) $(TARGET)

#Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCOMPILE:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

-include $(DEP)
