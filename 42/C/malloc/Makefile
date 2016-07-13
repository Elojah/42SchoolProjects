# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/23 13:00:56 by hdezier           #+#    #+#              #
#    Updated: 2016/06/29 19:04:13 by hdezier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

TARGET = libft_malloc.so
TARGET_HOST = libft_malloc_$(HOSTTYPE).so

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib

#Options
CC = gcc
SRC_EXT = .c
RM = rm -rf

#List classes here
CLASS = ft_malloc\
		ft_free\
		ft_realloc\
		show_alloc_mem\

#List interfaces here
INTERFACE =

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
LIBS = $(addprefix -L,$(LIB_DIR))

#Flags
CFLAGS = -Wall -Wextra -Werror -O3
LFLAGS =

#Libs
LIB_LOCAL =
LIB_GLOBAL =
LIB_OTHER =
LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))

#RULES
test: all
	gcc -L. -o a.out test_malloc/main.c -lft_malloc

all : dirbuild $(TARGET_HOST) link_hosttype

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET) $(TARGET_HOST)

re : fclean all

link_hosttype :
	@ln -sF $(TARGET_HOST) $(TARGET)

dirbuild:
	mkdir -p build

.PHONY: all clean fclean re dirbuild

.SILENT: dirbuild

#Build rules
$(TARGET_HOST) : $(OBJ)
	@echo "\n\033[1;4;34mDEP:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) -o $@ --shared $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@echo "\n\033[1;4;34mSRC:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
