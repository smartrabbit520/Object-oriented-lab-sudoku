#include "grid.h"       
#include <vector>
#include <string>
#include <iostream>
using namespace std; 

Grid::Grid(){
    
}

Grid::Grid(string grid){
    vector<vector<int>> temp;
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < grid.size(); j++)
        {
            row.push_back(grid[i * grid.size() + j] - '0');
        }
        temp.push_back(row);
    }
    Grid(temp);
}

Grid::Grid(vector<int> grid){
    vector<vector<int>> temp;
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < grid.size(); j++)
        {
            row.push_back(grid[i * grid.size() + j]);
        }
        temp.push_back(row);
    }
    Grid(temp);
}

Grid::Grid(const vector<vector<int>>& grid, int box_len){
    if (grid.size() != grid[0].size()) {
        throw runtime_error("grid.size() != grid[0].size()");
    }
    if (GRID_SIZE % box_len != 0) {
        throw runtime_error("grid.size() % box_len != 0");
    }
    this->GRID_SIZE = grid.size();
    this->BOX_LEN = box_len;
    this->BOX_SIZE = box_len * box_len;
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