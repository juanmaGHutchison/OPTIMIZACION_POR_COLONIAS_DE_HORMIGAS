CXX = clang++
CXXFLAGS = -g -Wall -std=c++11 -pedantic
BASURA = test-tablero *.o

all: clean test-tablero

test-tablero: pt.o
	$(CXX) $(LDFLAGS) -o $@ $^
test-tablero.o: pt.cpp

clean:
	$(RM) $(BASURA)
