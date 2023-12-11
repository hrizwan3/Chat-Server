#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <set>
#include <array>
#include "cell.hpp"

class Sudoku 
{
    private:
        Cell board[9][9];
        std::array<std::set<int>, 9> rowSet;
        std::array<std::set<int>, 9> colSet;
        std::array<std::array<std::set<int>, 3>, 3> boxSet;
    
    public:
        // Constructors / Assignment
        Sudoku();
        Sudoku(const Cell (&board)[9][9]);
        Sudoku(const Sudoku& other);
        
        Sudoku& operator=(const Sudoku& other);
        Sudoku(Sudoku&& other) noexcept;
        Sudoku& operator=(Sudoku&& other) noexcept;
        
        // Destructor
        ~Sudoku();

        // Cell Operations
        const Cell& getCell(int row, int col) const;
        void setCell(int row, int col, int val);

        // Board Operations
        bool checkSolved() const;
        bool isValidMove(int row, int col, int val) const;
        
        void printBoard() const;

        // Solver
        bool solve();
};

#endif // SUDOKU_HPP