/*
    Given a 2D matrix matrix, find the sum of the elements inside the rectangle 
    defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

    Range Sum Query 2D
    The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), 
    which contains sum = 8.

    Example:
    Given matrix = [
      [3, 0, 1, 4, 2],
      [5, 6, 3, 2, 1],
      [1, 2, 0, 1, 5],
      [4, 1, 0, 1, 7],
      [1, 0, 3, 0, 5]
    ]

    sumRegion(2, 1, 4, 3) -> 8
    update(3, 2, 2)
    sumRegion(2, 1, 4, 3) -> 10
    Note:
    The matrix is only modifiable by the update function.
    You may assume the number of calls to update and sumRegion function is distributed evenly.
    You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        
        mMatrix = matrix;
        mColSums = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix[0].size(); ++i)
        {
            for(int j = 0; j < matrix.size(); ++j)
            {
                mColSums[j][i] = (j == 0 ? 0 : mColSums[j - 1][i]) + matrix[j][i];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - mMatrix[row][col];
        for(int j = row; j < mMatrix.size(); ++j)
        {
            mColSums[j][col] += diff;
        }
        
        mMatrix[row][col] += diff;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = col1; i <= col2; ++i)
        {
            sum += mColSums[row2][i] - (row1 == 0 ? 0 : mColSums[row1 - 1][i]);
        }
        
        return sum;
    }
    
private:
    vector<vector<int>> mMatrix;
    vector<vector<int>> mColSums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
