/*
    Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
    connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

    Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

    Example 1:
    [[0,0,1,0,0,0,0,1,0,0,0,0,0],
     [0,0,0,0,0,0,0,1,1,1,0,0,0],
     [0,1,1,0,1,0,0,0,0,0,0,0,0],
     [0,1,0,0,1,1,0,0,1,0,1,0,0],
     [0,1,0,0,1,1,0,0,1,1,1,0,0],
     [0,0,0,0,0,0,0,0,0,0,1,0,0],
     [0,0,0,0,0,0,0,1,1,1,0,0,0],
     [0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
    Example 2:
    [[0,0,0,0,0,0,0,0]]
    Given the above grid, return 0.
    Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    int steps[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, getArea(grid, i, j));
            }
        }
        
        return maxArea;
    }
    
private:
    int getArea(vector<vector<int>>& grid, int r, int c)
    {
        int res = 0;
        queue<pair<int, int>> q;
        
        q.push(make_pair(r, c));
        grid[r][c] = -1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ++res;
            
            for(int i = 0; i < 4; ++i)
            {
                int xn = x + steps[i][0];
                int yn = y + steps[i][1];
                if(xn < 0 || xn >= grid.size() || 
                   yn < 0 || yn >= grid[0].size() || 
                   grid[xn][yn] != 1)
                    continue;
                
                grid[xn][yn] = -1;
                q.push(make_pair(xn, yn));
            }
        }
        
        return res;
    }
};
