#pragma once
#include <vector>
#include <string>
using namespace std;

class Grid {
    protected:
        vector<vector<int>> grid;
        int BOX_SIZE;
        int BOX_LEN;
        int GRID_SIZE;
    
    public:
        Grid() = delete;
        Grid(int grid_size, int box_size);
        Grid(const string& grid);
        Grid(const vector<int>& grid);
        Grid(const vector<vector<int>>& grid);
        Grid(const Grid& grid);
        ~Grid();

        bool operator==(const Grid& grid);

        vector<int> getRow(int row);
        vector<int> getColumn(int col);
        int getBox(int row, int col);
        bool setRow(int row, const vector<int>& values);
        bool setColumn(int col, const vector<int>& values);
        bool setBox(int row, int col, int value);
        bool setGrid(const vector<vector<int>>& grid);
        void printGrid();

        static vector<vector<int>> convertTo2DVector(const string& grid);
        static vector<vector<int>> convertTo2DVector(const vector<int>& grid);
};
