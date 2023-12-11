#include "sudoku.hpp"
#include <iostream>

using namespace std;

// Constructors
Sudoku::Sudoku() : board(), rowSet(), colSet(), boxSet() {
    for (int i{0}; i < 9; i++) {
        for (int j{0}; j < 9; j++) {
            board[i][j] = Cell(0, i, j);
        }
    }
}

// Copy constructor
Sudoku::Sudoku(const Sudoku& other) {
    *this = other;  // Delegate to copy assignment
}

// Copy assignment operator
Sudoku& Sudoku::operator=(const Sudoku& other) {
    if (this != &other) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                this->board[i][j] = other.board[i][j];
            }
            rowSet[i] = other.rowSet[i];
            colSet[i] = other.colSet[i];
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                boxSet[i][j] = other.boxSet[i][j];
            }
        }
    }
    return *this;
}

// Move constructor
Sudoku::Sudoku(Sudoku&& other) noexcept {
    *this = std::move(other);
}

// Move assignment operator
Sudoku& Sudoku::operator=(Sudoku&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                this->board[i][j] = std::move(other.board[i][j]);
            }
            rowSet[i] = std::move(other.rowSet[i]);
            colSet[i] = std::move(other.colSet[i]);
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                boxSet[i][j] = std::move(other.boxSet[i][j]);
            }
        }
    }
    return *this;
}

// Destructor
Sudoku::~Sudoku() {}

// Cell Operations
const Cell& Sudoku::getCell(int row, int col) const {
    return board[row][col];
}

void Sudoku::setCell(int row, int col, int val) {
    int oldVal = board[row][col].getValue();
    if (oldVal != 0) {
        rowSet[row].erase(oldVal);
        colSet[col].erase(oldVal);
        boxSet[row / 3][col / 3].erase(oldVal);
    }
    if (val >= 1 && val <= 9) {
        rowSet[row].insert(val);
        colSet[col].insert(val);
        boxSet[row / 3][col / 3].insert(val);
    }
    board[row][col].setValue(val);
}


// Board Operations
bool Sudoku::checkSolved() const {
    std::set<int> completeSet = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Check each row
    for (const auto& row : rowSet) {
        if (row != completeSet) {
            return false;
        }
    }

    // Check each column
    for (const auto& col : colSet) {
        if (col != completeSet) {
            return false;
        }
    }

    // Check each 3x3 box
    for (const auto& boxRow : boxSet) {
        for (const auto& box : boxRow) {
            if (box != completeSet) {
                return false;
            }
        }
    }

    return true;
}

// Board Operations
bool Sudoku::isValidMove(int row, int col, int val) const {
    if (rowSet[row].find(val) != rowSet[row].end()) return false;
    if (colSet[col].find(val) != colSet[col].end()) return false;
    if (boxSet[row / 3][col / 3].find(val) != boxSet[row / 3][col / 3].end()) return false;

    return true;
}

// Pretty print board
void Sudoku::printBoard() const {
    std::cout << "-------------------------\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 0)
                std::cout << "| ";
            std::cout << board[i][j].getValue() << " ";
            if ((j + 1) % 3 == 0)
                std::cout << "| ";
        }
        std::cout << std::endl;
        if ((i + 1) % 3 == 0)
            std::cout << "-------------------------\n";
    }
}


// Solver
bool Sudoku::solve() {
    // Find first empty cell
    int row{0};
    int col{0};
    bool found{false};
    for (int i{0}; i < 9; i++) {
        for (int j{0}; j < 9; j++) {
            if (board[i][j].getValue() == 0) {
                row = i;
                col = j;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // If no empty cells, then we're done
    if (!found) {
        return true;
    }

    // Try each value in the empty cell
    for (int val{1}; val <= 9; val++) {
        if (isValidMove(row, col, val)) {
            
            setCell(row, col, val);
            if (solve()) {
                return true;
            }
            setCell(row, col, 0);
        }
    }

    return false;
}

