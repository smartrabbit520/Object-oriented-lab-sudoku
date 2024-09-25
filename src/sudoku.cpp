#include <vector>
#include <string>
#include <set>
#include <cmath>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku(const string& grid): Grid(grid){
    checkGrid();
}

Sudoku::Sudoku(const vector<int>& grid): Grid(grid){
    checkGrid();
}

Sudoku::Sudoku(const vector<vector<int>>& grid): Grid(grid){
    checkGrid();
}

Sudoku::Sudoku(const Sudoku& grid): Grid(grid){
    checkGrid();
}

Sudoku::~Sudoku(){}

Sudoku::void checkGrid(){
    if (grid.GRID_SIZE != 9) {
        throw runtime_error("grid.size() != 9");
    }
    if (grid.BOX_LEN != 3) {
        throw runtime_error("grid.BOX_LEN != 3");
    }
    if (grid.BOX_SIZE != 9) {
        throw runtime_error("grid.BOX_SIZE != 9");
    }
}

vector<int> Sudoku::findPossibleValues(int row, int col)
{
    set<int> possibleValues;
    for (int i = 0; i < 10; i++)
    {
        possibleValues.insert(i + 1);
    }
    
    for (int i = 0; i < GRID_SIZE; i++)
    {
        possibleValues.erase(grid[row][i]);
    }
    for (int i = 0; i < GRID_SIZE; i++)
    {
        possibleValues.erase(grid[i][col]);
    }
    for (int i = 0; i < sqrt(BOX_LEN); i++)
    {
        for (int j = 0; j < sqrt(BOX_LEN); j++)
        {
            possibleValues.erase(grid[i + (row / BOX_LEN) * BOX_LEN][j + (col / BOX_LEN) * BOX_LEN]);
        }
    }
    return vector<int>(possibleValues.begin(), possibleValues.end());
}

vector<vector<vector<int>>> Sudoku::findAllPossibleValues()
{
    vector<vector<vector<int>>> allPossibleValues(GRID_SIZE, vector<vector<int>>(GRID_SIZE));
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] != 0){
                allPossibleValues[i][j].push_back(grid[i][j]);
            }
            else if (grid[i][j] == 0)
            {
                allPossibleValues[i][j].push_back(findPossibleValues(i, j));
            }
        }
    }
    return allPossibleValues;
}