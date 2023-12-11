CXX = g++

SFML_INCLUDE = C:/SFML-2.6.1/include
SFML_LIB = C:/SFML-2.6.1/lib

CXXFLAGS = -I$(SFML_INCLUDE) -std=c++11 -Wall
LDFLAGS = -L$(SFML_LIB) -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows

SOURCES = main.cpp cell.cpp solver.cpp sudoku.cpp # game.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = app.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o *.exe
