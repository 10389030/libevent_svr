FILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
DIR_PATH := $(dir $(FILE_PATH))
DIRNAME := $(notdir $(patsubst %/,%,$(dir $(FILE_PATH))))

# export variable
INC_TOOLKIT_NETWORK=-I$(DIR_PATH)
LIB_TOOLKIT_NETWORK=-L$(DIR_PATH) -ltoolkit_$(DIRNAME) -Wl,-rpath,/usr/local/lib -lglog -lpthread


# should override for compiling lib
INC_DEPENDENCY = $(INC_TOOLKIT_NETWORK)

