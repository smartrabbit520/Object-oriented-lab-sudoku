#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <stdexcept>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku(int grid_size, int box_size): Grid(grid_size, box_size){
    checkGrid();
}

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

void Sudoku::checkGrid(){
    if (this->GRID_SIZE != 9) {
        throw runtime_error("grid.size() != 9");
    }
    if (this->BOX_LEN != 3) {
        throw runtime_error("grid.BOX_LEN != 3");
    }
    if (this->BOX_SIZE != 9) {
        throw runtime_error("grid.BOX_SIZE != 9");
    }
}

bool Sudoku::setRow(int row, const vector<int>& values){
    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] < 0 || values[i] > 9) {
            throw invalid_argument("Values must be between 0 and 9.");
            return false;
        }
    }
    return super::setRow(row, values);
}

bool Sudoku::setColumn(int col, const vector<int>& values){
    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] < 0 || values[i] > 9) {
            throw invalid_argument("Values must be between 0 and 9.");
            return false;
        }
    }
    return super::setColumn(col, values);
}

bool Sudoku::setBox(int row, int col, int value){
    if (value < 0 || value > 9) {
        throw invalid_argument("Value must be between 0 and 9.");
        return false;
    }
    return super::setBox(row, col, value);
}

bool Sudoku::setGrid(const vector<vector<int>>& grid){
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] < 0 || grid[i][j] > 9) {
                throw invalid_argument("Values must be between 0 and 9.");
                return false;
            }
        }
    }
    return super::setGrid(grid);
}

vector<int> Sudoku::findPossibleValues(int row, int col)
{
    set<int> possibleValues;
    for (int i = 0; i < 9; i++)
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
                allPossibleValues[i][j] = findPossibleValues(i, j);
            }
        }
    }
    return allPossibleValues;
}