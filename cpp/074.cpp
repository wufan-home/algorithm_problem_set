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
        
        int s1 = 0;
        int s2 = matrix.size() - 1;
        while(s1 < s2)
        {
            int mid = s1 + (s2 - s1) / 2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                s1 = mid + 1;
            else
                s2 = mid;
        }
        
        int e1 = 0;
        int e2 = matrix.size() - 1;
        while(e1 < e2)
        {
            int mid = e1 + (e2 - e1) / 2;
            if(matrix[mid].back() == target)
                return true;
            else if(matrix[mid].back() < target)
                e1 = mid + 1;
            else
                e2 = mid;
        }
        
        //cout << s1 << " - " << e1 << endl;
        
        if(s1 < e1)
            return false;
        
        for(int i = e1; i <= s1; ++i)
        {
            int l = 0;
            int r = matrix[i].size();
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
