from grid import Grid

class Sudoku(Grid):
    def __init__(self, grid_size=None, box_size=None, grid=None):
        if isinstance(grid_size, int) and isinstance(box_size, int):
            super().__init__(grid_size=grid_size, box_size=box_size)
        elif isinstance(grid, str):
            super().__init__(grid=grid)
        elif isinstance(grid, list):
            super().__init__(grid=grid)
        else:
            raise TypeError("Invalid arguments for Sudoku initialization.")
        self.checkGrid()

    def checkGrid(self):
        if self.GRID_SIZE != 9:
            raise ValueError(f"grid.size() must be 9. grid.size(): {self.GRID_SIZE}")
        if self.BOX_LEN != 3:
            raise ValueError(f"grid.BOX_LEN must be 3. grid.BOX_LEN: {self.BOX_LEN}")
        if self.BOX_SIZE != 9:
            raise ValueError(f"grid.BOX_SIZE must be 9. grid.BOX_SIZE: {self.BOX_SIZE}")

    def setRow(self, row, values):
        for value in values:
            if value < 0 or value > 9:
                raise ValueError(f"Values must be between 0 and 9. Value: {value}")
        return super().setRow(row, values)

    def setColumn(self, col, values):
        for value in values:
            if value < 0 or value > 9:
                raise ValueError(f"Values must be between 0 and 9. Value: {value}")
        return super().setColumn(col, values)

    def setBox(self, row, col, value):
        if value < 0 or value > 9:
            raise ValueError(f"Value must be between 0 and 9. Value: {value}")
        return super().setBox(row, col, value)

    def setGrid(self, grid):
        for row in grid:
            for value in row:
                if value < 0 or value > 9:
                    raise ValueError(f"Values must be between 0 and 9. Value: {value}")
        return super().setGrid(grid)

    def findPossibleValues(self, row, col):
        possibleValues = set(range(1, 10))
        for i in range(self.GRID_SIZE):
            possibleValues.discard(self.grid[row][i])
        for i in range(self.GRID_SIZE):
            possibleValues.discard(self.grid[i][col])
        box_start_row = (row // self.BOX_LEN) * self.BOX_LEN
        box_start_col = (col // self.BOX_LEN) * self.BOX_LEN
        for i in range(box_start_row, box_start_row + self.BOX_LEN):
            for j in range(box_start_col, box_start_col + self.BOX_LEN):
                possibleValues.discard(self.grid[i][j])
        return list(possibleValues)

    def findAllPossibleValues(self):
        allPossibleValues = [[[self.grid[i][j]] if self.grid[i][j] != 0 else self.findPossibleValues(i, j) for j in range(self.GRID_SIZE)] for i in range(self.GRID_SIZE)]
        return allPossibleValues
