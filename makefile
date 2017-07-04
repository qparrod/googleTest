EXEC = test

COMPILE_OPTION= -Wall -g -O3 -std=c++11
CC=g++ $(COMPILE_OPTION)

CPPFLAGS+=-I/opt/gtest/x86_64/1.7.0-1/include
SRC += basic.cpp
LDLIBS = -pthread /opt/gtest/x86_64/1.7.0-1/lib/libgtest.a

all: run $(EXEC)

run: $(EXEC)
	@echo "--------------- Start Test ---------------"
	./$(EXEC)

test: basic.o
	@echo "--------------- Linking ---------------"
	$(CC) -o $@ $^ $(LDLIBS)
	make run

%.o: %.cpp
	@echo "--------------- Compiling $@ ---------------"
	$(CC) -c $< -o $@ $(CPPFLAGS)

clean:
	rm -rf *.o
	rm $(EXEC)
