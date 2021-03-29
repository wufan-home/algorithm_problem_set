/*
    Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

    Example:
    Input:
    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    Output:  [1,2,4,7,5,3,6,8,9]
    Explanation: alternative.

    Note:
    The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int row = matrix.size();
        if(row == 0)
            return res;
        
        int col = matrix[0].size();
        if(col == 0)
            return res;
        
        int num = row + col - 1;
        vector<int> temp(max(row, col), INT_MIN);
        bool reverse = false;
        for(int i = 0; i < num; ++i)
        {
            for(int j = i, l = 0; j >= 0; --j)
            {
                if(j >= row)
                    continue;
                
                if(i - j >= col)
                {
                    temp[l++] = INT_MIN;
                    break;
                }
                
                temp[l++] = matrix[j][i - j];
            }
            
            putEntriesDiagnally(temp, res, reverse);
            reverse = !reverse;
            temp[0] = INT_MIN;
        }
        
        return res;
    }
    
private:
    void putEntriesDiagnally(vector<int>& temp, vector<int>& res, bool reverse)
    {
        if(!reverse)
        {
            for(int i = 0; i < temp.size() && temp[i] != INT_MIN; ++i)
                res.push_back(temp[i]);
        }
        else
        {
            for(int i = temp.size() - 1; i >= 0; --i)
            {
                if(temp[i] == INT_MIN)
                    continue;

                res.push_back(temp[i]);
            }
        }
    }
};
