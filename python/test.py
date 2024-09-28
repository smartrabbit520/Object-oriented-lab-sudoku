from grid import Grid
from sudoku import Sudoku

def gridConstructorTest():
    print("grid constructor test")
    print("input grid size and box size")
    grid_size = 9
    box_size = 9
    grid1 = Grid(grid_size=grid_size, box_size=box_size)
    grid1.printGrid()
    print()
    
    print("input string")
    s2 = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
    grid2 = Grid(grid=s2)
    grid2.printGrid()
    print()

    print("input 1D list")
    s3 = [i for i in range(4)]
    grid3 = Grid(grid=s3)
    grid3.printGrid()
    print()

    print("input 2D list")
    s4 = [[i + j for j in range(3)] for i in range(3)]
    grid4 = Grid(grid=s4)
    grid4.printGrid()
    print()

    # wrong input
    try:
        print("wrong input 1")
        grid_size = 9
        box_size = 8
        grid6 = Grid(grid_size=grid_size, box_size=box_size)
    except Exception as e:
        print(e)
    print()

    try:
        print("wrong input 2")
        grid_size = 10
        box_size = 9
        grid6 = Grid(grid_size, box_size)
    except Exception as e:
        print(e)
    print()

    # wrong input 3
    try:
        print("wrong input 3")
        s6 = [[0] * 4 for _ in range(3)]
        grid6 = Grid(grid=s6)
    except Exception as e:
        print(e)
    print()

def gridGetSetTest():
    print("grid get set test")
    s = [[i + j for j in range(3)] for i in range(3)]
    grid = Grid(grid=s)
    print("original grid")
    grid.printGrid()
    row = grid.getRow(0)
    print("row 0:", row)
    for i in range(len(row)):
        grid.setBox(0, i, -1)
    print("modified grid")
    grid.printGrid()
    print()

def grid_test():
    print("grid test")
    gridConstructorTest()
    gridGetSetTest()

def sudokuConstructorTest():
    print("sudoku constructor test")
    print("true input")
    s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
    sudoku = Sudoku(grid=s)
    sudoku.printGrid()
    print()

    print("wrong input 1")
    try:
        grid_size = 16
        box_size = 4
        sudoku = Sudoku(grid_size, box_size)
    except Exception as e:
        print(e)
    print()
    
    print("wrong input 2")
    try:
        grid_size = 9
        box_size = 1
        sudoku = Sudoku(grid_size, box_size)
    except Exception as e:
        print(e)
    print()

def sudokuGetSetTest():
    print("sudoku get set test")
    s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
    sudoku = Sudoku(grid=s)

    print("original grid")
    sudoku.printGrid()
    print()
    
    row = sudoku.getRow(0)
    print("row 0:", row)

    for i in range(len(row)):
        sudoku.setBox(0, i, 5)
    print("modified grid")
    sudoku.printGrid()
    print()

    # wrong input: > 10
    try:
        print("wrong input: > 10")
        sudoku.setBox(0, 0, 11)
    except Exception as e:
        print(e)
    print()

    # wrong input: < 0
    try:
        print("wrong input: < 0")
        sudoku.setBox(0, 0, -1)
    except Exception as e:
        print(e)
    print()

def solveTest():
    print("solve test")

    print("original grid")
    s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
    sudoku1 = Sudoku(grid=s)
    sudoku1.printGrid()
    result = sudoku1.findAllPossibleValues()
    print("result")
    for i in range(len(result)):
        for j in range(len(result[i])):
            print(f"row: {i} col: {j} possible values: {result[i][j]}")
    print()

    print("original grid")
    sudokuVec = [
        5, 3, 0, 0, 7, 0, 0, 0, 0,
        6, 0, 0, 1, 9, 5, 0, 0, 0,
        0, 9, 8, 0, 0, 0, 0, 6, 0,
        8, 0, 0, 0, 6, 0, 0, 0, 3,
        4, 0, 0, 8, 0, 3, 0, 0, 1,
        7, 0, 0, 0, 2, 0, 0, 0, 6,
        0, 6, 0, 0, 0, 0, 2, 8, 0,
        0, 0, 0, 4, 1, 9, 0, 0, 5,
        0, 0, 0, 0, 8, 0, 0, 7, 9
    ]
    sudoku2 = Sudoku(grid=sudokuVec)
    sudoku2.printGrid()
    result = sudoku2.findAllPossibleValues()
    print("result")
    for i in range(len(result)):
        for j in range(len(result[i])):
            print(f"row: {i} col: {j} possible values: {result[i][j]}")
    print()

    print("original grid")
    sudokuVec2D = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]
    sudoku3 = Sudoku(grid=sudokuVec2D)
    sudoku3.printGrid()
    result = sudoku3.findAllPossibleValues()
    print("result")
    for i in range(len(result)):
        for j in range(len(result[i])):
            print(f"row: {i} col: {j} possible values: {result[i][j]}")
    print()

def sudoku_test():
    print("sudoku test")
    sudokuConstructorTest()
    sudokuGetSetTest()
    solveTest()

if __name__ == "__main__":
    grid_test()
    sudoku_test()
    