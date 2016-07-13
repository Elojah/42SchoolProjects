TARGET = btree
FILES = btree.ml
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
SRC_DIR = srcs
OBJ_DIR = objs
LIBS =
CMOS = $(SRC:$(SRC_DIR)/%.ml=$(OBJ_DIR)/%.cmo)
CMXS = $(SRC:$(SRC_DIR)/%.ml=$(OBJ_DIR)/%.cmx)
TMPS = $(SRC:.ml=.ml~) Makefile~
RM = /bin/rm -rf
OCC = ocamlc
OPT = ocamlopt
DEP = ocamldep
OFLAGS = -I $(OBJ_DIR)
CFLAGS =
LFLAGS =

.PHONY: all clean $(OBJ_DIR) fclean re

.SILENT: $(OBJ_DIR)

all: $(OBJ_DIR) depend $(TARGET)

$(TARGET): $(TARGET).byt $(TARGET).opt
	ln -sf $(TARGET).byt $(TARGET)

$(TARGET).byt: $(CMOS)
	$(OCC) $(CFLAGS) -o $(TARGET).byt $(LIBS) $(LFLAGS) $(CMOS)
$(TARGET).opt: $(CMXS)
	$(OPT) $(CFLAGS) -o $(TARGET).opt $(LIBS:.cma=.cmxa) $(LFLAGS) $(CMXS)

.SUFFIXES: .ml .mli .cmo .cmi .cmx

$(OBJ_DIR)/%.cmo : $(SRC_DIR)/%.ml
	$(OCC) $(OFLAGS) -o $@ -c $^
$(OBJ_DIR)/%.cmi : $(SRC_DIR)/%.mli
	$(OCC) $(OFLAGS) -o $@ -c $^
$(OBJ_DIR)/%.cmx : $(SRC_DIR)/%.ml
	$(OPT) $(OFLAGS) -o $@ -c $^

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

depend:
	$(DEP) $(SRC) > .depend

clean:
	$(RM) $(CMOS) $(CMXS) $(TMPS)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(TARGET)
	$(RM) .depend
	$(RM) .depend.input
	$(RM) $(TARGET).opt
	$(RM) $(TARGET).byt

re: fclean all

.depend.input: Makefile
	@echo -n '--Checking Ocaml input files: '
	@(ls $(SMLIY) $(SMLIY:.ml=.mli) 2>/dev/null || true) \
		> .depend.new
	@diff .depend.new .depend.input 2>/dev/null 1>/dev/null && \
		(echo 'unchanged'; rm -f .depend.new) || \
		(echo 'changed'; mv .depend.new .depend.input)

depend: .depend

.depend:: $(SMLIY) .depend.input
	@echo '--Re-building dependencies'
	$(CAMLDEP) $(SMLIY) $(SMLIY:.ml=.mli) > .depend

include .depend
