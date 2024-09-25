#include <vector>
#include <string>
#include "grid.h"
using namespace std;

class Sudoku : protected Grid {
    public:
        Sudoku() = delete;
        Sudoku(const string& grid);
        Sudoku(const vector<int>& grid);
        Sudoku(const vector<vector<int>>& grid);
        Sudoku(const Sudoku& grid);
        ~Sudoku();

        void checkGrid();

        vector<int> findPossibleValues(int row, int col);
        vector<vector<vector<int>>> findAllPossibleValues();
};
