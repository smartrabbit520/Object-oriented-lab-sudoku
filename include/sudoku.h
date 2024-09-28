#pragma once
#include <vector>
#include <string>
#include "grid.h"
using namespace std;

class Sudoku : public Grid {
    public:
        Sudoku() = delete;
        Sudoku(int grid_size, int box_size);
        Sudoku(const string& grid);
        Sudoku(const vector<int>& grid);
        Sudoku(const vector<vector<int>>& grid);
        Sudoku(const Sudoku& grid);
        ~Sudoku();

        void checkGrid() const;
        bool setRow(int row, const vector<int>& values);
        bool setColumn(int col, const vector<int>& values);
        bool setBox(int row, int col, int value);
        bool setGrid(const vector<vector<int>>& grid);

        vector<int> findPossibleValues(int row, int col) const;
        vector<vector<vector<int>>> findAllPossibleValues() const;
};
