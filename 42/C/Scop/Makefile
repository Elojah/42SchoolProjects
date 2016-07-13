TARGET = bin/scop

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib

#Options
CC = clang-3.6
SRC_EXT = .c
RM = rm -rf

#List classes here
CLASS = main\
		init_camera\
		loop\
		refresh\
		render\
		load/load_obj\
		load/load_bmp\
		load/load_shaders\
		callback/key_callback\
		callback/mouse_callback\

#List interfaces here
INTERFACE = \

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))
LIBS = $(addprefix -L,$(LIB_DIR))

#Flags
CFLAGS =-MMD -Wall -Wextra -Werror -O3 -g
LFLAGS =

#Libs
LIB_LOCAL = \
			$(LIB_DIR)/libft\
			$(LIB_DIR)/glfw\

LIB_GLOBAL = \
			pthread\
			Xxf86vm\
			Xinerama\
			Xcursor\
			Xi\
			dl\
			Xrandr\
			X11\
			GL\
			glfw3\
			ft\
			m\

LIB_OTHER = \
			-Llib/glfw/src\

LIBS += $(LIB_OTHER)
LIBS += $(addprefix -L, $(LIB_LOCAL))
LIBS += $(addprefix -l,$(LIB_GLOBAL))

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))
INC += \

#RULES
all : dirbin dirlib $(TARGET)

clean :
	make clean -C $(LIB_DIR)/libft
	$(RM) $(BUILD_DIR)

fclean :
	make fclean -C $(LIB_DIR)/libft
	$(RM) $(BUILD_DIR) $(TARGET)

re : fclean all

dirbin:
	mkdir -p bin

dirlib:
	make -C $(LIB_DIR)/libft
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
