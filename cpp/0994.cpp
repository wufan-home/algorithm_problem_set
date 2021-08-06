/*
    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



    Example 1:

    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

    Example 2:

    Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

    Example 3:

    Input: grid = [[0,2]]
    Output: 0
    Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.



    Constraints:

        m == grid.length
        n == grid[i].length
        1 <= m, n <= 10
        grid[i][j] is 0, 1, or 2.


*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> steps({0, 1, 0, -1, 0});
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        queue<int> rotten;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                fresh += grid[i][j] == 1;
                if (grid[i][j] == 2) {
                    rotten.push(i * 10000 + j);
                }
            }
        }
        
        int ans = 0;
        if (fresh == 0) {
            return ans;
        }
        
        for (int level = rotten.size(); !rotten.empty();) {
            int rx = rotten.front() / 10000;
            int ry = rotten.front() % 10000;
            rotten.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nx = rx + steps[i];
                int ny = ry + steps[i + 1];
                
                if (nx < 0 || nx >= row || ny < 0 || ny >= col || grid[nx][ny] != 1) {
                    continue;
                }
                
                grid[nx][ny] = 2;
                --fresh;
                rotten.push(nx * 10000 + ny);
            }
            
            if (--level == 0) {
                ++ans;
                level = rotten.size();
            }
        }
        
        return fresh == 0 ? ans - 1 : -1;
    }
};
