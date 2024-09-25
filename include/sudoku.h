#include <vector>
#include <string>
#include "grid.h"
using namespace std;

class Sudoku : public Grid {
    private:
        vector<vector<int>> grid;
        const int BOX_SIZE = 9;
        const int BOX_LEN = 3;
        const int GRID_SIZE = 9;
    
    public:
        Sudoku();
        Sudoku(string grid);
        Sudoku(vector<int> grid);
        Sudoku(vector<vector<int>> grid);
        Sudoku(const Sudoku& grid);
        ~Sudoku();

        int getRow(int row);
        int getColumn(int col);
        int getBox(int row, int col);
        void printGrid();

        vector<int> findPossibleValues(int row, int col);
        vector<vector<vector<int>>> findAllPossibleValues();
};
