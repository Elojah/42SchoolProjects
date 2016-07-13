TARGET = bin/arkanoid

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
		loop\
		render\
		load_map\
		key_callback\
		load_shaders\
		add_unit\
		move_player\

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
			lib/libft\

LIB_GLOBAL = \
			glfw3\
			ft\
			m\

LIB_OTHER = \
			-framework Cocoa\
			-framework OpenGL\
			-framework IOKit\
			-framework CoreVideo\
			-Llib/glfw/src\

LIBS += $(addprefix -L, $(LIB_LOCAL))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))
INC += \
		-Ilib/glfw/include\

#RULES
all : dirbin dirlib $(TARGET)

clean :
	make clean -C lib/libft
	$(RM) $(BUILD_DIR)

fclean :
	make fclean -C lib/libft
	$(RM) $(BUILD_DIR) $(TARGET)

re : fclean all

dirbin:
	mkdir -p bin

dirlib:
	make -C lib/libft
	sh ./util/install_lib.sh

.PHONY: all clean fclean re

.SILENT: dirbuild dirbin dirlib

#Build rule
$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLNK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

#Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCMP:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
