/*
    In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

    A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

    Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.



    Example 1:

    Input: x = 2, y = 1
    Output: 1
    Explanation: [0, 0] → [2, 1]

    Example 2:

    Input: x = 5, y = 5
    Output: 4
    Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]



    Constraints:

        |x| + |y| <= 300
*/

class Solution {
public: 
    int minKnightMoves(int x, int y) {
        x *= (x < 0 ? -1 : 1);
        y *= (y < 0 ? -1 : 1);
        
        if (x < y) {
            swap(x, y);
        }
        
        int dim = max(x, max(y, 2)) + 1;
        
        vector<vector<int>> dp_memo(dim, vector<int>(dim, 0));
        dp_memo[1][0] = 3;
        dp_memo[1][1] = 2;
        dp_memo[2][1] = 1;
        dp_memo[2][0] = 2;
        
        if (x + y >= 3) {
            dp(x, y, dp_memo);
        }
        
        return dp_memo[x][y];
    }
    
private:
    int dp(int x, int y, vector<vector<int>>& dp_memo)
    {
        x *= (x < 0 ? -1 : 1);
        y *= (y < 0 ? -1 : 1);
        
        if (x < y) {
            swap(x, y);
        }
        
        if (x + y >= 3 && dp_memo[x][y] == 0) {
            dp_memo[x][y] = min(dp(x - 2, y - 1, dp_memo), dp(x - 1, y - 2, dp_memo)) + 1;
        }
        
        return dp_memo[x][y];
    }
};

