TARGET = bin/mod1

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib

#Options
CC = clang++
SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = main\
		AObject\
		Objects/Sea\
		Objects/Rain\
		Parser/Tokens/AToken\
		Parser/Tokens/Scope\
		Parser/Tokens/Comment\
		Parser/Tokens/Number\
		Parser/Parser\
		Objects/Landscape\
		Camera\
		Map\
		CocoaWin\

#List interfaces here
INTERFACES = \

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))
LIBS = $(addprefix -L,$(LIB_DIR))

#Flags
CFLAGS =-MMD -Wall -Wextra -Werror -O3 -g -std=c++98
LFLAGS =

#Libs
LIB_LOCAL = \
			lib/LoadShaders\

LIB_GLOBAL = \
			LoadShaders\
			glfw3\

LIB_OTHER = \
			-framework Cocoa\
			-framework OpenGL\
			-framework IOKit\
			-framework CoreVideo\
			-Llib/glfw/src\

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(LIB_OTHER)
LIBS += $(addprefix -l,$(LIB_GLOBAL))

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))
INC += \
		-Ilib/glfw/include\
		-Ilib/glm\

#RULES
all : dirbin dirlib $(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET)
	$(RM) lib/glfw
	$(RM) lib/glm

re : fclean all

dirbin:
	mkdir -p bin

dirlib:
	sh ./util/install_lib.sh

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

-include $(DEP)
