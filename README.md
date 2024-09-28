# 面向对象作业：实现Sudoku类

## 项目文件结构介绍

### 根目录

- `README.md`：项目的说明文档。
- `CMakeLists.txt`：CMake 构建系统的配置文件。
- `build/`：构建目录，包含 CMake 生成的文件和编译输出。

### include 目录

- `grid.h`：Grid 类的头文件。
- `sudoku.h`：Sudoku 类的头文件。

### python 目录

- `grid.py`：Grid 类的 Python 实现。
- `sudoku.py`：Sudoku 类的 Python 实现。
- `test.py`：Python 测试文件。
- `result.txt`：Python 测试结果文件。

### src 目录

- `grid.cpp`：Grid 类的实现文件。
- `sudoku.cpp`：Sudoku 类的实现文件。

### test 目录

- `test.cpp`：C++ 测试文件。
- `result.txt`：C++测试结果文件。

## 运行方式

### C++
1. 安装C++编译器和CMake
2. 创建并切换到build目录
    ```sh
    mkdir build
    cd build
    ```
3. 编译并构建项目
    ```sh
    cmake ..
    make
    ```
4. 运行可执行文件
    ```sh
    ./SudokuSolver
    ```

### Python

1. 安装python

2. 运行Python测试脚本：
    ```sh
    cd python
    python3 test.py
    ```

## C++部分代码介绍

### Grid 类

#### 构造函数

- `Grid() = delete;`
  - 禁用默认无参构造函数，因为未定义grid_size和box_size。
- `Grid(int grid_size, int box_size)`
  - 初始化一个指定grid_size和box_size的网格。
- `Grid(const std::string& grid)`
  - 根据字符串初始化网格。
- `Grid(const std::vector<int>& grid)`
  - 根据一维整数向量初始化网格。
- `Grid(const std::vector<std::vector<int>>& grid)`
  - 根据二维整数向量初始化网格。
- `Grid(const Grid& grid)`
  - 拷贝构造函数。

#### 构造函数辅助函数
- `vector<vector<int>> Grid::convertTo2DVector(const vector<int>& grid)`
  - 将一维整数向量转化为二维整数向量。
- `vector<vector<int>> Grid::convertTo2DVector(const string& grid)`
  - 将字符串转化为二维整数向量。

#### 查询方法
- `std::vector<int> getRow(int row) const`
  - 获取指定行的值。
- `std::vector<int> getColumn(int col) const`
  - 获取指定列的值。
- `std::vector<int> getBox(int row, int col) const`
  - 获取指定位置的值。

#### 修改方法
- `bool setRow(int row, const std::vector<int>& values)`
  - 设置指定行的值。
- `bool setColumn(int col, const std::vector<int>& values)`
  - 设置指定列的值。
- `bool setBox(int row, int col, int value)`
  - 设置指定位置的值。
- `bool setGrid(const std::vector<std::vector<int>>& grid)`
  - 设置整个网格的值。

### 其他方法
- `void Grid::printGrid() const`
  - 输出整个Grid。

### Sudoku 类

#### 构造函数
- `Sudoku() = delete;`
  - 禁用默认无参构造函数，因为未定义grid_size和box_size。
- `Sudoku(int grid_size, int box_size)`
  - 初始化一个指定grid_size和box_size的数独网格。
- `Sudoku(const std::string& grid)`
  - 从字符串初始化数独网格。
- `Sudoku(const std::vector<int>& grid)`
  - 从一维整数向量初始化数独网格。
- `Sudoku(const std::vector<std::vector<int>>& grid)`
  - 从二维整数向量初始化数独网格。
- `Sudoku(const Sudoku& grid)`
  - 拷贝构造函数。

#### 构造函数辅助函数
- `void checkGrid()`
  - 检查数独网格的有效性。

#### 查询方法
查询和父类Grid完全一致，故可以直接使用父类的。

#### 修改方法
- `bool setRow(int row, const std::vector<int>& values)`
  - 设置指定行的值，并检查值的有效性。
- `bool setColumn(int col, const std::vector<int>& values)`
  - 设置指定列的值，并检查值的有效性。
- `bool setBox(int row, int col, int value)`
  - 设置指定位置的值，并检查值的有效性。
- `bool setGrid(const std::vector<std::vector<int>>& grid)`
  - 设置整个网格的值，并检查值的有效性。

#### 数独求解方法
- `std::vector<int> findPossibleValues(int row, int col)`
  - 查找指定位置的可能值。
- `std::vector<std::vector<std::vector<int>>> findAllPossibleValues()`
  - 查找所有位置的可能值。

## Python部分代码介绍

### Grid 类

#### 构造函数
- `Grid(grid_size=None, box_size=None, grid=None)`
  - 初始化一个指定grid_size和box_size的网格，或从字符串、一维列表或二维列表初始化网格。

#### 构造函数辅助函数
- `convertTo2DVector(grid)`
  - 将一维列表或字符串转换为二维列表。

#### 查询方法
- `getRow(self, row)`
  - 获取指定行的值。
- `getColumn(self, col)`
  - 获取指定列的值。
- `getBox(self, row, col)`
  - 获取指定位置的值。

#### 修改方法
- `setRow(self, row, values)`
  - 设置指定行的值。
- `setColumn(self, col, values)`
  - 设置指定列的值。
- `setBox(self, row, col, value)`
  - 设置指定位置的值。
- `setGrid(self, grid)`
  - 设置整个网格的值。

#### 其他方法
- `printGrid(self)`
  - 打印网格。
- `__eq__(self, other)`
  - 重载等于运算符，比较两个 Grid 对象是否相等。

### Sudoku 类

#### 构造函数
- `Sudoku(grid_size=None, box_size=None, grid=None)`
  - 初始化一个指定grid_size和box_size的数独网格，或从字符串、一维列表或二维列表初始化数独网格。

#### 构造函数辅助函数
- `checkGrid(self)`
  - 检查数独网格的有效性。

#### 修改方法
- `setRow(self, row, values)`
  - 设置指定行的值，并检查值的有效性。
- `setColumn(self, col, values)`
  - 设置指定列的值，并检查值的有效性。
- `setBox(self, row, col, value)`
  - 设置指定位置的值，并检查值的有效性。
- `setGrid(self, grid)`
  - 设置整个网格的值，并检查值的有效性。

#### 数独求解方法
- `findPossibleValues(self, row, col)`
  - 查找指定位置的可能值。
- `findAllPossibleValues(self)`
  - 查找所有位置的可能值。
