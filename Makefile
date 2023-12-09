CXX=g++
CXXFLAGS=-std=c++20 -Wall -Werror -g
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

all: a.out

a.out: main.o sudoku.o cell.o solver.o
	$(CXX) $(CXXFLAGS) main.o sudoku.o cell.o solver.o $(SFMLFLAGS) -o a.out

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f *.o a.out
