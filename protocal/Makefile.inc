DIRECTORY := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

include $(DIRECTORY)/http1.1/Makefile.inc

INC_PROTOCAL=-I$(DIRECTORY)
