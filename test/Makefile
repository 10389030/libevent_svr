DIRECTORY := $(dir $(lastword $(MAKEFILE_LIST)))
include $(DIRECTORY)/Makefile.inc

SRC_DIR=./
OBJ_DIR=./
LIB_DIR=./

OBJ_EXT=.bin
SRC_EXT=.cpp
OBJECTS=$(patsubst $(SRC_DIR)%$(SRC_EXT),$(OBJ_DIR)%$(OBJ_EXT),$(wildcard $(SRC_DIR)*$(SRC_EXT)))

all:$(OBJECTS)
	@echo "$(OBJECTS) ==> $@"
	$(AR) rc $(LIB_TARGET) $<
	@echo ""

$(OBJ_DIR)%$(OBJ_EXT):$(SRC_DIR)%$(SRC_EXT)
	@echo -e "\033[1;33m\nCompiling $< ==> $@ \033[0m..."
	$(CXX) $(INC_DEPENDENCY) $(C_FLAGS)  $< -o $@
	@echo ""

clean:
	rm -rf $(OBJECTS) $(LIB_TARGET)
	
