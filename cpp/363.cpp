/*
    Given a non-empty 2D matrix matrix and an integer k, 
    find the max sum of a rectangle in the matrix such that its sum is no larger than k.

    Example:
    Given matrix = [
      [1,  0, 1],
      [0, -2, 3]
    ]
    k = 2
    The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

    Note:
    The rectangle inside the matrix must have an area > 0.
    What if the number of rows is much larger than the number of columns?
    
    Note:
    If your new structure is one more dimension than the input and the adding line is all zero,
    use 1 as the starting point of the loop.
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty())
            return INT_MIN;
        
        int maxSum = INT_MIN;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> sums(row + 1, vector<int>(col + 1, 0));
        for(int r = 1; r <= row; ++r)
        {
            int rowSum = 0;
            for(int c = 1; c <= col; ++c)
            {
                rowSum += matrix[r - 1][c - 1];
                sums[r][c] = rowSum + sums[r - 1][c];
                for(int i = 1; i <= r; ++i)
                {
                    for(int j = 1; j <= c; ++j)
                    {
                        int localSum = sums[r][c] - sums[i - 1][c] - sums[r][j - 1] + sums[i - 1][j - 1];
                        if(localSum <= k)
                            maxSum = max(maxSum, localSum);
                    }
                }
            }
        }
        
        return maxSum;
    }
};
