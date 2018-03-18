FILE_PATH = $(abspath $(lastword $(MAKEFILE_LIST)))
DIR_PATH = $(dir $(FILE_PATH))
DIRNAME = $(notdir $(patsubst %/,%,$(dir $(FILE_PATH))))
PARENT_NAME = $(notdir $(patsubst %/,%,$(dir $(abspath $(DIR_PATH)))))

# export variable
INC_PROTOCAL_HTTP=-I$(DIR_PATH)
LIB_PROTOCAL_HTTP=-L$(DIR_PATH) -l$(PARENT_NAME)_$(DIRNAME) -Wl,-rpath,/usr/local/lib -lglog -lpthread


# should override for compiling lib
LIB_TARGET=lib$(PARENT_NAME)_$(DIRNAME).a
INC_DEPENDENCY = $(INC_PROTOCAL_HTTP)

