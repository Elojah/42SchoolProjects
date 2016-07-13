# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 15:21:48 by hdezier           #+#    #+#              #
#    Updated: 2016/05/25 15:21:51 by hdezier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = fillit

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR =

#Options
CC = clang
SRC_EXT = .c
RM = rm -rf

#List classes here
CLASS = main\
		error\
		file_to_pieces\
		resolve\
		fill_result_in_size\
		calculus_dead_blocks\
		print_pieces\

#List interfaces here
INTERFACE = \

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))
LIBS = $(addprefix -L,$(LIB_DIR))

#Flags
CFLAGS =-MMD -Wall -Wextra -Werror -O3
LFLAGS =

#Libs
LIB_LOCAL = \

LIB_GLOBAL = \

LIB_OTHER = \

LIBS += $(LIB_OTHER)
LIBS += $(addprefix -L, $(LIB_LOCAL))
LIBS += $(addprefix -l, $(LIB_GLOBAL))

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))

#RULES
all : $(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET)

re : fclean all

dirbin:
	mkdir -p bin

.PHONY: all clean fclean re

.SILENT: dirbuild dirbin

#Build rule
$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLNK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

#Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCMP:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

#-include $(DEP)
