/*
    Given two sparse matrices A and B, return the result of AB.

    You may assume that A's column number is equal to B's row number.

    Example:

    A = [
      [ 1, 0, 0],
      [-1, 0, 3]
    ]

    B = [
      [ 7, 0, 0 ],
      [ 0, 0, 0 ],
      [ 0, 0, 1 ]
    ]


         |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
    AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                      | 0 0 1 |
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty() || A[0].empty() || B.empty() || B[0].empty())
            return vector<vector<int>>();
        
        int row = A.size();
        int col = B[0].size();
        vector<vector<int>> C(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i)
        {
            vector<int> index;
            for(int j = 0; j < A[0].size(); ++j)
            {
                if(A[i][j])
                    index.push_back(j);
            }
            
            for(int j = 0; j < index.size(); ++j)
            {
                int scale = A[i][index[j]];
                for(int k = 0; k < col; ++k)
                    C[i][k] += scale * B[index[j]][k];
            }
        }
        
        return C;
    }
};
