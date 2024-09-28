import math

class Grid:
    def __init__(self, grid_size=None, box_size=None, grid=None):
        if grid_size is not None and box_size is not None:
            if int(math.sqrt(box_size)) * int(math.sqrt(box_size)) != box_size:
                raise ValueError(f"Box size must be a perfect square. Box size: {box_size}")
            if grid_size % int(math.sqrt(box_size)) != 0:
                raise ValueError(f"Grid size must be divisible by box len. Grid size: {grid_size} Box size: {box_size} Box len: {int(math.sqrt(box_size))}")
            self.GRID_SIZE = grid_size
            self.BOX_SIZE = box_size
            self.BOX_LEN = int(math.sqrt(box_size))
            self.grid = [[0] * grid_size for _ in range(grid_size)]
        elif isinstance(grid, str):
            self.grid = self.convertTo2DVector(grid)
            self.GRID_SIZE = len(self.grid)
            self.BOX_SIZE = self.GRID_SIZE
            self.BOX_LEN = int(math.sqrt(self.GRID_SIZE))
        elif isinstance(grid, list):
            if all(isinstance(i, int) for i in grid):
                self.grid = self.convertTo2DVector(grid)
            elif all(isinstance(i, list) for i in grid):
                if len(grid) != len(grid[0]):
                    raise ValueError(f"Grid must be square. Rows: {len(grid)} Columns: {len(grid[0])}")
                self.grid = grid
            else:
                raise TypeError("Grid must be a string or a list of integers or a 2D list of integers.")
            self.GRID_SIZE = len(self.grid)
            self.BOX_SIZE = self.GRID_SIZE
            self.BOX_LEN = int(math.sqrt(self.GRID_SIZE))
        else:
            raise TypeError("Invalid arguments for Grid initialization.")
        
    def __copy__(self):
        new_grid = Grid(grid_size=self.GRID_SIZE, box_size=self.BOX_SIZE)
        new_grid.grid = self.grid.copy()
        return new_grid

    def __deepcopy__(self, memo):
        new_grid = Grid(grid_size=self.GRID_SIZE, box_size=self.BOX_SIZE)
        new_grid.grid = copy.deepcopy(self.grid, memo)
        return new_grid
    
    @staticmethod
    def convertTo2DVector(grid):
        if isinstance(grid, list):
            size = int(math.sqrt(len(grid)))
            return [[grid[i * size + j] for j in range(size)] for i in range(size)]
        elif isinstance(grid, str):
            size = int(math.sqrt(len(grid)))
            if size * size != len(grid):
                raise ValueError(f"String length must be a perfect square. String length: {len(grid)}")
            return [[int(grid[i * size + j]) for j in range(size)] for i in range(size)]
        else:
            raise TypeError("Grid must be a string or a list of integers.")

    def __eq__(self, other):
        if not isinstance(other, Grid):
            return False
        return self.GRID_SIZE == other.GRID_SIZE and self.BOX_SIZE == other.BOX_SIZE and self.BOX_LEN == other.BOX_LEN and self.grid == other.grid

    def getRow(self, row):
        return self.grid[row]

    def getColumn(self, col):
        return [self.grid[i][col] for i in range(self.GRID_SIZE)]

    def getBox(self, row, col):
        return self.grid[row][col]

    def setRow(self, row, values):
        if row >= self.GRID_SIZE or row < 0:
            raise ValueError(f"Row index out of range. Row: {row}")
        if len(values) != self.GRID_SIZE:
            raise ValueError(f"Values size must be equal to grid size. Values size: {len(values)}")
        self.grid[row] = values
        return True

    def setColumn(self, col, values):
        if col >= self.GRID_SIZE or col < 0:
            raise ValueError(f"Column index out of range. Column: {col}")
        if len(values) != self.GRID_SIZE:
            raise ValueError(f"Values size must be equal to grid size. Values size: {len(values)}")
        for i in range(self.GRID_SIZE):
            self.grid[i][col] = values[i]
        return True

    def setBox(self, row, col, value):
        if row >= self.GRID_SIZE or row < 0:
            raise ValueError(f"Row index out of range. Row: {row}")
        if col >= self.GRID_SIZE or col < 0:
            raise ValueError(f"Column index out of range. Column: {col}")
        self.grid[row][col] = value
        return True

    def setGrid(self, grid):
        if len(grid) != self.GRID_SIZE:
            raise ValueError(f"Grid size must be equal to grid size. Grid size: {len(grid)}")
        for row in grid:
            if len(row) != self.GRID_SIZE:
                raise ValueError(f"Grid size must be equal to grid size. Grid size: {len(row)}")
        self.grid = grid
        return True

    def printGrid(self):
        for row in self.grid:
            print(" ".join(map(str, row)))
