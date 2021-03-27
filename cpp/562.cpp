/*
    Given a 01 matrix M, find the longest line of consecutive one in the matrix. 
    The line could be horizontal, vertical, diagonal or anti-diagonal.

    Example:
    Input:
    [[0,1,1,0],
     [0,1,1,0],
     [0,0,0,1]]
    Output: 3
    Hint: The number of elements in the given matrix will not exceed 10,000.
*/

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int row = M.size();
        if(row == 0)
            return 0;
        
        int col = M[0].size();
        if(col == 0)
            return 0;
            
        h = vector<int>(row, 0);
        v = vector<int>(col, 0);
        for(int i = 1 - row; i < col; ++i)
            d[i] = 0;
        
        for(int i = 0; i < row + col - 1; ++i)
            ad[i] = 0;
        
        int maxLen = 0;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(M[i][j] == 0)
                {
                    h[i] = 0;
                    v[j] = 0;
                    d[j - i] = 0;
                    ad[i + j] = 0;
                    continue;
                }
                
                maxLen = max(maxLen, ++h[i]);
                maxLen = max(maxLen, ++v[j]);
                maxLen = max(maxLen, ++d[j - i]);
                maxLen = max(maxLen, ++ad[i + j]);
            }
        }
        
        return maxLen;
    }
    
private:
    vector<int> h;
    vector<int> v;
    unordered_map<int, int> d;
    unordered_map<int, int> ad;
};
