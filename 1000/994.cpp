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
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> directions({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        
        // Count
        int total_rotate = 0;
        int total_fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                total_fresh += (grid[i][j] == 1);
                if (grid[i][j] == 2) {
                    ++total_rotate;
                    q.push(make_pair(i, j));
                }
            }
        }
        
        int res = 0;
        while(!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                int curX = q.front().first;
                int curY = q.front().second;
                
                for (int i = 0; i < 4; ++i) {
                    int nextX = curX + directions[i][0];
                    int nextY = curY + directions[i][1];
                    
                    if (nextX >= 0 && nextX < row && nextY >= 0 && nextY < col && grid[nextX][nextY] == 1) {
                        grid[nextX][nextY] = 2;
                        --total_fresh;
                        q.push(make_pair(nextX, nextY));
                    }
                }
                
                q.pop();
            }
            res += (q.size() > 0);
        }
        
        return total_fresh == 0 ? res : -1;
    }
};
