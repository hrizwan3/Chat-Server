#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <set>
#include <array>
#include "cell.hpp"

class Sudoku 
{
    private:
        Cell board[9][9]; // 9x9 array of Cells
        std::array<std::set<int>, 9> rowSet; // 9 sets of ints
        std::array<std::set<int>, 9> colSet; // 9 sets of ints
        std::array<std::array<std::set<int>, 3>, 3> boxSet; // 3x3 array of sets of ints
    
    public:
        // Constructors / Assignment
        Sudoku();
        Sudoku(const Sudoku& other);
        
        // Copy assignment operator
        Sudoku& operator=(const Sudoku& other);

        // Move constructor
        Sudoku(Sudoku&& other) noexcept;

        // Move assignment operator
        Sudoku& operator=(Sudoku&& other) noexcept;
        
        // Destructor
        ~Sudoku();

        // Cell Operations
        const Cell& getCell(int row, int col) const;
        void setCell(int row, int col, int val);

        // Board Operations
        bool checkSolved() const;
        bool isValidMove(int row, int col, int val) const;
        
        // Print
        void printBoard() const;

        // Solver
        bool solve();
};

#endif // SUDOKU_HPP