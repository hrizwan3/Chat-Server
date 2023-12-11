#include <iostream>
#include "cell.hpp"

using namespace std;

// Constructors
Cell::Cell() : value(0), row(0), col(0) {}

Cell::Cell(int value, int row, int col) : value(value), row(row), col(col) {}

// Copy constructor
Cell::Cell(const Cell& other) : value(other.value), row(other.row), col(other.col) {}

// Copy assignment operator
Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        this->value = other.value;
        this->row = other.row;
        this->col = other.col;
    }
    return *this;
}

// Move constructor
Cell::Cell(Cell&& other) noexcept : value(std::move(other.value)), row(std::move(other.row)), col(std::move(other.col)) {}

// Move assignment operator
Cell& Cell::operator=(Cell&& other) noexcept {
    if (this != &other) {
        this->value = std::move(other.value);
        this->row = std::move(other.row);
        this->col = std::move(other.col);
    }
    return *this;
}

// Destructor
Cell::~Cell(){}

// Getters / Setters
void Cell::setValue(int val) {
    value = val;
}

int Cell::getValue() const {
    return value;
}

int Cell::getRow() const {
    return row;
}

int Cell::getCol() const {
    return col;
}