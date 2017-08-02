/*
    Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
    find the kth smallest element in the matrix.

    Note that it is the kth smallest element in the sorted order, not the kth distinct element.

    Example:

    matrix = [
       [ 1,  5,  9],
       [10, 11, 13],
       [12, 13, 15]
    ],
    k = 8,

    return 13.
    Note: 
    You may assume k is always valid, 1 <= k <= n2.
*/

class compare
{
    vector<vector<int>> *mpMatrix;
public:
    compare(vector<vector<int>>* pMatrix) {mpMatrix = pMatrix;}
    bool operator() (const pair<int, int> &l, const pair<int, int> &r) const
    {
        return (*mpMatrix)[l.first][l.second] >= (*mpMatrix)[r.first][r.second];
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        if(row == 0 || col == 0 || k > row * col)
            return INT_MAX;
        
        if(k == 1)
            return matrix[0][0];
        
        if(k == row * col)
            return matrix[row - 1][col - 1];
        
        int res = INT_MIN;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq(&matrix);
        pq.push(make_pair(0, 0));
        while(!pq.empty() && k)
        {
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            
            //cout << x << ", " << y << ": " << matrix[x][y] << ", " << k << endl;
            
            if(--k == 0)
            {
                res = matrix[x][y];
                break;
            }
            
            if(x + 1 < row && visited[x + 1][y] == false)
            {
                visited[x + 1][y] = true;
                pq.push(make_pair(x + 1, y));
            }
            
            if(y + 1 < col && visited[x][y + 1] == false)
            {
                visited[x][y + 1] = true;
                pq.push(make_pair(x, y + 1));
            }
        }
        
        return res;
    }    
};
