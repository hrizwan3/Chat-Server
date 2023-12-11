#pragma once
#include "sudoku.hpp"
#include <iostream>

using namespace std;

bool loadSudoku(Sudoku& sudoku, const char* filename);
bool saveSudoku(const Sudoku& sudoku, const char* filename);

void displayGameOptions(const std::string options[]);
void displayBoardOptions(const std::string boards[]);

