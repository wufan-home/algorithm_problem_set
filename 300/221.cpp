/*
    Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

    For example, given the following matrix:

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    Return 4.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {  
        int result = 0;  
        if(matrix.empty())  
            return result;  
        const int n = matrix.size();  
        const int m = matrix[0].size();  
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));  
        for(int i = 0; i < n; ++i)  
            for(int j = 0; j < m; ++j){  
                if(matrix[i][j] == '1'){  
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1])) + 1;  
                    result = max(result, dp[i + 1][j + 1]);  
                }  
            }  
        return result * result;  
    }
};
