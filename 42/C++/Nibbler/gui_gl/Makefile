TARGET = gui-gl.so

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR =

CC = clang++
SRC_EXT = .cpp
RM = rm -rf

CLASS = \
		GUIGL\

INTERFACE = \

SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))
LIBS = $(addprefix -L,$(LIB_DIR))

CFLAGS = -MMD -Wall -Wextra -Werror -O3 -std=c++98
LFLAGS =

LIB_LOCAL = \
			lib/LoadShaders\

LIB_GLOBAL = \
			LoadShaders\
			glfw3\

LIB_OTHER = \
			-framework Cocoa\
			-framework Carbon\
			-framework OpenGL\
			-framework IOKit\
			-framework CoreVideo\
			-Llib/glfw/src\

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))
INC += \
		-I../game/incs/\
		-Ilib/glfw/include\

#RULES
all : installib $(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET)
	$(RM) lib/glfw

re : fclean all

installib:
	sh ./util/install_glfw.sh

.PHONY: all clean fclean re

.SILENT: dirbuild dirbin installib

$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLNK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) -dynamiclib $^ -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCMP:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

-include $(DEP)
