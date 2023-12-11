#ifndef UTILITIES_HPP

#include "sudoku.hpp"
#include <iostream>

using namespace std;

// Load and save
bool loadSudoku(Sudoku& sudoku, const char* filename);
bool saveSudoku(const Sudoku& sudoku, const char* filename);

// Display options
void displayGameOptions(const std::string options[]);
void displayBoardOptions(const std::string boards[]);

#endif // UTILITIES_HPP