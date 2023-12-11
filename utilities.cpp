#include "utilities.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Load Sudoku from file
bool loadSudoku(Sudoku& sudoku, const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    int row{0};
    int col{0};
    int val{0};
    while (file >> val) {
        sudoku.setCell(row, col, val);
        col++;
        if (col == 9) {
            col = 0;
            row++;
        }
    }

    return true;
}

// Save Sudoku to file
bool saveSudoku(const Sudoku& sudoku, const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (int i{0}; i < 9; i++) {
        for (int j{0}; j < 9; j++) {
            file << sudoku.getCell(i, j).getValue() << " ";
        }
        file << endl;
    }

    return true;
}

// Display options
void displayGameOptions(const std::string options[]) {
    for (int i{0}; i < 2; i++) {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
}

void displayBoardOptions(const std::string boards[]) {
    for (int i{0}; i < 5; i++) {
        std::cout << i + 1 << ". " << boards[i] << std::endl;
    }
}
