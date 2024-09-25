#include <iostream>
#include "sudoku.h"
using namespace std;

bool grid_test(){
    std:string s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Grid grid(s);
    grid.printGrid();
    return 0;
}

bool sudoku_test(){
    std:string s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku(s);
    sudoku.printGrid();
    vector<vector<vector<int>>>result = sudoku.findAllPossibleValues();
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << "row: " << i << " col: " << j << " possible values: ";
            for (int k = 0; k < result[i][j].size(); k++)
            {
                cout << result[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

int main(){
    grid_test();
    sudoku_test();
}