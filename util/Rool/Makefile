TARGET = runner

#Directories
BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib

#Options
CC = clang++-3.6
SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = main\
		patterns/UsualClass\
		patterns/UsualInterface\
		patterns/ReplaceClassName\
		models/Menu\
		models/Window\
		menus/Boot\
		menus/ClassList\
		menus/MemberList\
		GUI\
		Project\
		SortItems\
		ClassTemplate\
		MemberTemplate\
		ModuleFactory\

#List interfaces here
INTERFACE = IModule\
			ITemplate\

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))

LIBS = $(addprefix -L,$(LIB_DIR))

#Flags
CFLAGS =-MMD -Wall -Wextra -Werror -O3 -std=c++98
LFLAGS =

#Libs
LIB_LOCAL = lib/parseStr lib/fileManip
LIB_GLOBAL = ncurses menu parseStr fileManip
LIB_OTHER =
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
	$(RM) $(BUILD_DIR) $(BIN_DIR)

re : fclean all

dirbin:
	mkdir -p bin

.PHONY: all clean fclean re

.SILENT: dirbuild dirbin

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
