include ./Makefile.inc

C_FLAGS += -O2
CXX = g++
INCS = $(INC_TOOLKIT)
LIBS = -levent $(LIB_TOOLKIT_NETWORK) -Wl,-rpath,/usr/local/lib -lglog -lpthread

main: main.cpp
	$(CXX) $(C_FLAGS) $(INCS) $< -o $@ $(LIBS)

clean:
	rm -rf ./main

run:
	GLOG_logtostderr=0 sudo ./main
	
