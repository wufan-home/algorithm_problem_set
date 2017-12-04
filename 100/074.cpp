/*
    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    For example,

    Consider the following matrix:

    [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        int r1 = 0; 
        int r2 = matrix.size() - 1;
        while(r1 < r2)
        {
            int mid = r1 + (r2 - r1) / 2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                r1 = mid + 1;
            else
                r2 = mid;
        }
        
        if(matrix[r1][0] > target)
            --r1;
        
        for(int i = r1; i < matrix.size(); ++i)
        {
            int l = 0;
            int r = matrix[i].size() - 1;
            while(l < r)
            {
                int mid = l + (r - l) / 2;
                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] < target)
                    l = mid + 1;
                else
                    r = mid;
            }
            
            if(matrix[i][l] == target)
                return true;
        }
        
        return false;
    }
};
