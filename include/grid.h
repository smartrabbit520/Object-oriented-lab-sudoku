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

        virtual int getRow(int row);
        virtual int getColumn(int col);
        virtual int getBox(int row, int col);
        virtual void printGrid();
};
