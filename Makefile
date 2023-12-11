CXX = g++

SOURCES = main.cpp cell.cpp sudoku.cpp utilities.cpp
EXECUTABLE = sudoku

all: $(EXECUTABLE)

$(EXECUTABLE): 
	$(CXX) -o $(EXECUTABLE) $(SOURCES)

clean:
	del $(EXECUTABLE).exe *.o
