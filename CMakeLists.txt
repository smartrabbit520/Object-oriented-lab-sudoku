cmake_minimum_required(VERSION 3.10)
project(SudokuSolver)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 添加源文件
set(SOURCES
    src/grid.cpp
    src/sudoku.cpp
    test/test.cpp
)

# 添加可执行文件
add_executable(SudokuSolver ${SOURCES})
