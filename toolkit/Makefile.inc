DIRECTORY := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

include $(DIRECTORY)/network/Makefile.inc

INC_PROTOCAL=-I$(DIRECTORY)
