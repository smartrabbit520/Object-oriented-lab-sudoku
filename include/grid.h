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
        Grid();
        Grid(string grid);
        Grid(vector<int> grid);
        Grid(vector<vector<int>> grid);
        Grid(const Grid& grid);
        ~Grid();

        vector<int> getRow(int row);
        vector<int> getColumn(int col);
        int getBox(int row, int col);
        void printGrid();
};
