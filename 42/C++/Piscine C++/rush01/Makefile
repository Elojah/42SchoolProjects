TARGET = bin/runner

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR =

#Options
CC = clang++
SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = main\
		modules/Cat\
		modules/CPUInfo\
		modules/DateTime\
		modules/OSInfo\
		modules/RAMInfo\
		AWindow\
		modules/UserInfo\
		displays/FLDisplay\
		displays/NCursesDisplay\
		Master\

#List interfaces here
INTERFACE = \
		IMonitorDisplay\
		IMonitorModule\

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))
LIBS = $(addprefix -L,$(LIB_DIR))

#Flags
CFLAGS =-MMD -Wall -Wextra -Werror -O3 -std=c++98 -Wno-unused-parameter
LFLAGS = `lib/fltk-1.3.3/fltk-config --cxxflags --ldflags --use-images`

#Libs
LIB_LOCAL = lib/fltk-1.3.3\

LIB_GLOBAL = \
			ncurses\
			fltk\

LIB_OTHER = \
			-framework Cocoa\

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix , $(addprefix -I, $(LIB_LOCAL)))

#RULES
all : dirbin install_fltk $(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET) lib/fltk-1.3.3

re : fclean all

dirbin:
	mkdir -p bin

install_fltk:
	sh ./util/install_fltk.sh

.PHONY: all clean fclean re

.SILENT: dirbuild dirbin

#Build rule
$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLNK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) $(LFLAGS)

#Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCMP:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

-include $(DEP)
