COMPILE_OPTION= -Wall -g -O3 -std=c++11
CC=g++ $(COMPILE_OPTION)

CPPFLAGS+=-I/opt/gtest/x86_64/1.7.0-1/include
SRC += basic.cpp
LDLIBS = -pthread /opt/gtest/x86_64/1.7.0-1/lib/libgtest.a

all: runbasic rundeath basictest deathtest flagstest


flagtest: flag.o
	$(CC) -o $@ $^ $(LDLIBS)
	./flagtest

deathtest: death.o
	$(CC) -o $@ $^ $(LDLIBS)
	./deathtest

basictest: basic.o
	$(CC) -o $@ $^ $(LDLIBS)
	./basictest

%.o: %.cpp
	@echo "--------------- Compiling $@ ---------------"
	$(CC) -c $< -o $@ $(CPPFLAGS)

clean:
	rm -rf *.o
	rm -rf *test

