#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "grid.h"
using namespace std; 

vector<vector<int>> Grid::convertTo2DVector(const vector<int>& grid) {
    int size = sqrt(grid.size());
    vector<vector<int>> temp(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = grid[i * size + j];
        }
    }
    return temp;
}

vector<vector<int>> Grid::convertTo2DVector(const string& grid) {
    int size = sqrt(grid.size());
    if (size * size != grid.size()) {
        throw invalid_argument("String length must be a perfect square.");
    }
    vector<vector<int>> temp(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = grid[i * size + j] - '0'; // 假设字符串中的每个字符是一个数字
        }
    }
    return temp;
}

Grid::Grid(int grid_size, int box_size){
    // initialize grid with 0
    if (grid_size % box_size != 0) {
        throw invalid_argument("Grid size must be divisible by box size.");
    }
    if (int(sqrt(box_size)) * int(sqrt(box_size)) != box_size) {
        throw invalid_argument("Grid size must be a perfect square.");
    }
    this->GRID_SIZE = grid_size;
    this->BOX_SIZE = box_size;
    this->BOX_LEN = sqrt(box_size);
    this->grid = vector<vector<int>>(grid_size, vector<int>(grid_size));
}

Grid::Grid(const string& grid): Grid(convertTo2DVector(grid)){}

Grid::Grid(const vector<int>& grid): Grid(convertTo2DVector(grid)){}

Grid::Grid(const vector<vector<int>>& grid){
    this->GRID_SIZE = grid.size();
    this->BOX_SIZE = this->GRID_SIZE;
    this->BOX_LEN = sqrt(this->GRID_SIZE);
    this->grid = grid;
}

Grid::Grid(const Grid& grid){
    this->GRID_SIZE = grid.GRID_SIZE;
    this->BOX_SIZE = grid.BOX_SIZE;
    this->BOX_LEN = grid.BOX_LEN;
    this->grid = grid.grid;
}

Grid::~Grid(){

}

vector<int> Grid::getRow(int row){
    return grid[row];
}

vector<int> Grid::getColumn(int col){
    for (int i = 0; i < GRID_SIZE; i++)
    {
        cout << grid[i][col] << endl;
    }
}

int Grid::getBox(int row, int col){
    return grid[row][col];
}

bool Grid::setRow(int row, const vector<int>& values){
    if (row >= GRID_SIZE || row < 0) {
        throw invalid_argument("Row index out of range.");
        return false;
    }
    if (values.size() != GRID_SIZE) {
        throw invalid_argument("Values size must be equal to grid size.");
        return false;
    }
    grid[row] = values;
    return true;
}

bool Grid::setColumn(int col, const vector<int>& values){
    if (col >= GRID_SIZE || col < 0) {
        throw invalid_argument("Column index out of range.");
        return false;
    }
    if (values.size() != GRID_SIZE) {
        throw invalid_argument("Values size must be equal to grid size.");
        return false;
    }
    for (int i = 0; i < GRID_SIZE; i++)
    {
        grid[i][col] = values[i];
    }
    return true;
}

bool Grid::setBox(int row, int col, int value){
    if (row >= GRID_SIZE || row < 0) {
        throw invalid_argument("Row index out of range.");
        return false;
    }
    if (col >= GRID_SIZE || col < 0) {
        throw invalid_argument("Column index out of range.");
        return false;
    }
    grid[row][col] = value;
    return true;
}

bool Grid::setGrid(const vector<vector<int>>& grid){
    if (grid.size() != GRID_SIZE) {
        throw invalid_argument("Grid size must be equal to grid size.");
        return false;
    }
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (grid[i].size() != GRID_SIZE) {
            throw invalid_argument("Grid size must be equal to grid size.");
            return false;
        }
    }
    this->grid = grid;
    return true;
}

void Grid::printGrid(){
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}