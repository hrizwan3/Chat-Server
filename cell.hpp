#ifndef CELL_HPP
#define CELL_HPP

class Cell
{
    private:
        int value;
        int row;
        int col;
    public:
        // Constructors / Assignment
        Cell();
        Cell(int value, int row, int col);
        Cell(const Cell& other);

        Cell& operator=(const Cell& other);
        Cell(Cell&& other) noexcept;
        Cell& operator=(Cell&& other) noexcept;

        // Destructor
        ~Cell();

        void setValue(int val);

        int getValue() const;
        int getRow() const;
        int getCol() const;

};

#endif // CELL_HPP