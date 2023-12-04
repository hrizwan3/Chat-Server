
CXX=g++
CXXFLAGS=-std=c++20 -Wall -Werror -g

all: a.out

a.out: main.o sudoku.o cell.o solver.o
	$(CXX) $(CXXFLAGS) main.o sudoku.o

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f *.o a.out