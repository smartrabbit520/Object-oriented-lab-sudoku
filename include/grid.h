#include <vector>
#include <string>
using namespace std;

class Grid {
    private:
        vector<vector<int>> grid;
        int BOX_SIZE;
        int GRID_SIZE;
    
    public:
        Grid();
        Grid(string grid);
        Grid(vector<int> grid);
        Grid(vector<vector<int>> grid);
        Grid(const Grid& grid);
        ~Grid();

        int getRow(int row);
        int getColumn(int col);
        int getBox(int row, int col);
        void printGrid();
};
