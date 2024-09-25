#include <vector>
#include <string>
#include <set>
#include <cmath>
#include "sudoku.h"
using namespace std;

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
    for (int i = 0; i < sqrt(BOX_SIZE); i++)
    {
        for (int j = 0; j < sqrt(BOX_SIZE); j++)
        {
            row: 5  col: 7
            第六行第八列
            3,4,5行
            6,7,8列
            0-2 + 5 / 3 * 3
            possibleValues.erase(grid[i + (row / BOX_SIZE) * BOX_SIZE][j + (col / BOX_SIZE) * BOX_SIZE]);
        }
    }
}

vector<vector<int>> Sudoku::findAllPossibleValues()
{
    return vector<vector<int>>();
}