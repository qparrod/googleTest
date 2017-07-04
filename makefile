#COMPILE_OPTION= -Wall -g -O3
CC=g++ $(COMPILE_OPTION)

CPPFLAGS+=-I/opt/gtest/x86_64/1.7.0-1/include
SRC += basic.cpp
LIBS = /opt/gtest/x86_64/1.7.0-1/lib/libgtest.a
LDLIBS = -pthread



test:
	@echo "--------------- Compiling $(SRC) ---------------"
	$(CC) $(SRC) $(LDLIBS) $(CPPFLAGS) $(LIBS) -o $@ 

