#include <iostream>
#include "sudoku.hpp"
#include "utilities.hpp"

using namespace std;

/***************************
 * 
 * 
 * 
 * ****************************/

int main(int argc, char* argv[]) {
    cout << "Hello! Welcome to Fraudulent Sudoku (with a solver)" << endl;
    string choices[] = {"Load last game", "Create new game"};
    string boards[] = {"easy1", "easy2", "easy3", "grid1", "grid2"};

    cout << "Please select an option:" << endl;
    displayGameOptions(choices);
    int val;
    cin >> val;

    cout << "You selected: " << choices[val - 1] << endl;

    Sudoku sudoku;
    if (val == 0) {
        if (!loadSudoku(sudoku, "saves/save.txt")) {
            cout << "Game not found, loading a preset" << endl;
            loadSudoku(sudoku, "preset-games/easy1.txt");
        }
    } else {
        cout << "Please select a game:" << endl;
        displayBoardOptions(boards);
        cin >> val;
        loadSudoku(sudoku, ("preset-games/" + boards[val - 1] + ".txt").c_str());
    }

    bool playing{true};

    while (!sudoku.checkSolved()) {
        sudoku.printBoard();
        cout << "Please enter a row, column, and value (separated by spaces), or type \"-1 -1 -1\" to stop:" << endl;
        int row, col, value;
        cin >> row >> col >> value;
        if (row == -1 && col == -1 && value == -1) {
            cout << "Would you like to save your game? (y/n)" << endl;
            char save;
            cin >> save;
            if (save == 'y') {
                saveSudoku(sudoku, "saves/save.txt");
            }
            break;
        } else if (sudoku.isValidMove(row - 1, col - 1, value)) {
            sudoku.setCell(row - 1, col - 1, value);
        } else {
            cout << "Invalid move!" << endl;
        }
    }

    if (sudoku.checkSolved()) {
        cout << "Congratulations! You solved the puzzle!" << endl;
    }
    return 0;
}