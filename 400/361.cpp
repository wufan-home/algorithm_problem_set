/*
    Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), 
    return the maximum enemies you can kill using one bomb.
    The bomb kills all the enemies in the same row and column 
    from the planted point until it hits the wall since the wall is too strong to be destroyed.
    Note that you can only put the bomb at an empty cell.

    Example:
    For the given grid

    0 E 0 0
    E 0 W E
    0 E 0 0

    return 3. (Placing a bomb at (1,1) kills 3 enemies)
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        int total = 0;
        int rowCount = 0;
        vector<int> colCount(grid[0].size(), 0);
        
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(j == 0 || grid[i][j - 1] == 'W')
                {
                    rowCount = 0;
                    for(int k = j; k < grid[i].size() && grid[i][k] != 'W'; ++k)
                        rowCount += (grid[i][k] == 'E');
                }
                
                if(i == 0 || grid[i - 1][j] == 'W')
                {
                    colCount[j] = 0;
                    for(int k = i; k < grid.size() && grid[k][j] != 'W'; ++k)
                        colCount[j] += (grid[k][j] == 'E');
                }
                
                if(grid[i][j] == '0')
                    total = max(total, rowCount + colCount[j]);
            }
        }
        
        return total;
    }
};
