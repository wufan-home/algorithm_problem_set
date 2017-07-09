/*
    Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

    The distance between two adjacent cells is 1.
    Example 1: 
    Input:

    0 0 0
    0 1 0
    0 0 0
    Output:
    0 0 0
    0 1 0
    0 0 0
    Example 2: 
    Input:

    0 0 0
    0 1 0
    1 1 1
    Output:
    0 0 0
    0 1 0
    1 2 1
    Note:
    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.
*/

class Solution {
public:
    Solution()
    {
        steps = vector<vector<int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> distance(row, vector<int>(col, 0));
        
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(matrix[i][j] != 0)
                    updateDistance(matrix, i, j, distance);
            }
        }
        
        return distance;
    }
    
private:
    vector<vector<int>> steps;
    
    void updateDistance(const vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& distance)
    {
        queue<pair<int, int>> q;
        int dis = 0;
        q.push(make_pair(r, c));
        q.push(make_pair(-1, -1));
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == -1 && y == -1)
            {
                if(q.empty())
                    break;
                
                q.push(make_pair(-1, -1));
                ++dis;
            }
            
            for(int i = 0; i < steps.size(); ++i)
            {
                if(x + steps[i][0] < 0 || x + steps[i][0] >= matrix.size())
                    continue;
                
                if(y + steps[i][1] < 0 || y + steps[i][1] >= matrix[0].size())
                    continue;
                
                if(matrix[x + steps[i][0]][y + steps[i][1]] == 0)
                {
                    distance[r][c] = dis + 1;
                    return;
                }
                
                q.push(make_pair(x + steps[i][0], y + steps[i][1]));
            }
        }
    }
};
