#include <iostream>
#include "grid.h"
#include "sudoku.h"
using namespace std;

void gridConstructorTest(){
    cout << "grid constructor test" << endl;
    // Grid(int grid_size, int box_size);
    cout << "test Grid(int grid_size, int box_size)" << endl;
    int grid_size = 9;
    int box_size = 9;
    Grid grid1(grid_size, box_size);
    grid1.printGrid();
    cout << endl;
    
    // Grid(const string& grid);
    cout << "test Grid(const string& grid)" << endl;
    std:string s2 = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Grid grid2(s2);
    grid2.printGrid();
    cout << endl;

    // Grid(const vector<int>& grid);
    cout << "test Grid(const vector<int>& grid)" << endl;
    vector<int>s3(4);
    for (int i = 0; i < s3.size(); i++) {
        s3[i] = i;
    }
    Grid grid3(s3);
    grid3.printGrid();
    cout << endl;

    // Grid(const vector<vector<int>>& grid);
    cout << "test Grid(const vector<vector<int>>& grid)" << endl;
    vector<vector<int>>s4(3, vector<int>(3));
    for (int i = 0; i < s4.size(); i++) {
        for (int j = 0; j < s4[i].size(); j++) {
            s4[i][j] = i + j;
        }
    }
    Grid grid4(s4);
    grid4.printGrid();
    cout << endl;

    // Grid(const Grid& grid);
    cout << "test Grid(const Grid& grid)" << endl;
    Grid grid5(grid4);
    grid5.printGrid();
    cout << boolalpha;
    cout << "grid4 == grid5: " << bool(grid4 == grid5) << endl;
    cout << endl;

    // wrong input: Grid(int grid_size, int box_size);
    try {
        cout << "wrong input: Grid(int grid_size, int box_size);" << endl;
        int grid_size = 9;
        int box_size = 8;
        Grid grid6(grid_size, box_size);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    try {
        cout << "wrong input: Grid(int grid_size, int box_size);" << endl;
        int grid_size = 10;
        int box_size = 9;
        Grid grid6(grid_size, box_size);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    // wrong input: others
    try {
        cout << "wrong input: others" << endl;
        vector<vector<int>>s6(3, vector<int>(4));
        Grid grid6(s6);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << endl;
}

void gridGetSetTest(){
    cout << "grid get set test" << endl;
    // vector<int> getRow(int row);
    cout << "test vector<int> getRow(int row)" << endl;
    vector<vector<int>>s(3, vector<int>(3));
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i].size(); j++) {
            s[i][j] = i + j;
        }
    }
    Grid grid(s);
    cout << "original grid" << endl;
    grid.printGrid();
    vector<int> row = grid.getRow(0);
    cout << "row 0: ";
    for (int i = 0; i < row.size(); i++) {
        cout << row[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < row.size(); i++) {
        grid.setBox(0, i, -1);
    }
    cout << "modified grid" << endl;
    grid.printGrid();
    cout << endl;
}

void grid_test(){
    cout << "grid test" << endl;
    gridConstructorTest();
    gridGetSetTest();
}

void sudokuConstructorTest(){
    cout << "sudoku constructor test" << endl;
    cout<< "true input" << endl;
    std:string s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku(s);
    sudoku.printGrid();
    cout << endl;

    cout << "wrong input1" << endl;
    try {
        int grid_size = 16;
        int box_size = 4;
        Sudoku sudoku(grid_size, box_size);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << endl;
    
    cout << "wrong input2" << endl;
    try {
        int grid_size = 9;
        int box_size = 1;
        Sudoku sudoku(grid_size, box_size);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << endl;
}

void sudokuGetSetTest(){
    cout << "sudoku get set test" << endl;
    std:string s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku(s);

    cout << "original grid" << endl;
    sudoku.printGrid();
    cout << endl;
    
    vector<int> row = sudoku.getRow(0);
    cout << "row 0: ";
    for (int i = 0; i < row.size(); i++) {
        cout << row[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < row.size(); i++) {
        sudoku.setBox(0, i, 5);
    }
    cout << "modified grid" << endl;
    sudoku.printGrid();
    cout << endl;

    // wrong input: > 10
    try {
        cout << "wrong input: > 10" << endl;
        sudoku.setBox(0, 0, 11);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    // wrong input: < 0
    try {
        cout << "wrong input: < 0" << endl;
        sudoku.setBox(0, 0, -1);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << endl;
}

void solveTest(){
    cout << "solve test" << endl;

    cout << "string input" << endl;
    cout << "original grid" << endl;
    std:string s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku1(s);
    sudoku1.printGrid();
    vector<vector<vector<int>>>result = sudoku1.findAllPossibleValues();
    cout << "result" << endl;
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
    cout << endl;

    cout << "vector<int> input" << endl;
    cout << "original grid" << endl;
    vector<int> sudokuVec = {
        5, 3, 0, 0, 7, 0, 0, 0, 0,
        6, 0, 0, 1, 9, 5, 0, 0, 0,
        0, 9, 8, 0, 0, 0, 0, 6, 0,
        8, 0, 0, 0, 6, 0, 0, 0, 3,
        4, 0, 0, 8, 0, 3, 0, 0, 1,
        7, 0, 0, 0, 2, 0, 0, 0, 6,
        0, 6, 0, 0, 0, 0, 2, 8, 0,
        0, 0, 0, 4, 1, 9, 0, 0, 5,
        0, 0, 0, 0, 8, 0, 0, 7, 9
    };
    Sudoku sudoku2(sudokuVec);
    sudoku2.printGrid();
    result = sudoku2.findAllPossibleValues();
    cout << "result" << endl;
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
    cout << endl;

    cout << "vector<vector<int>> input" << endl;
    cout << "original grid" << endl;
    vector<vector<int>> sudokuVec2D = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    Sudoku sudoku3(sudokuVec2D);
    sudoku3.printGrid();
    result = sudoku3.findAllPossibleValues();
    cout << "result" << endl;
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
    cout << endl;
}

void sudoku_test(){
    cout << "sudoku test" << endl;
    sudokuConstructorTest();
    sudokuGetSetTest();
    solveTest();
}

int main(){
    grid_test();
    sudoku_test();
}