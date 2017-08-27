/*
    Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, 
    the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" 
    touches the right and bottom edges.

    Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

    Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

    Note:
    The order of returned grid coordinates does not matter.
    Both m and n are less than 150.
    Example:

    Given the following 5x5 matrix:

      Pacific ~   ~   ~   ~   ~ 
           ~  1   2   2   3  (5) *
           ~  3   2   3  (4) (4) *
           ~  2   4  (5)  3   1  *
           ~ (6) (7)  1   4   5  *
           ~ (5)  1   1   2   4  *
              *   *   *   *   * Atlantic

    Return:

    [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

class Solution {
public:
    int steps[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return vector<pair<int, int>>();
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<char>> seas(row, vector<char>(col, 'U'));
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<pair<int, int>> res;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(seas[i][j] != 'A')
                    whichSea(matrix, i, j, seas, visited);
                
                if(seas[i][j] == 'A')
                    res.push_back(make_pair(i, j));
            }
        }

        return res;
    }
    
private:
    char whichSea(const vector<vector<int>> &matrix, int x, int y, vector<vector<char>> &seas, vector<vector<bool>> &visited)
    {
        
        for(int i = 0; i < 4; ++i)
        {
            int nextX = x + steps[i][0];
            int nextY = y + steps[i][1];
            
            if(nextX < 0 || nextY < 0)
                seas[x][y] = seas[x][y] == 'a' ? 'A' : 'p';
            
            if(nextX >= (int)matrix.size() || nextY >= (int)matrix[0].size())
                seas[x][y] = seas[x][y] == 'p' ? 'A' : 'a';
            
            if(seas[x][y] == 'A')
                break;
            
            if(nextX < 0 || nextY < 0 || 
               nextX >= matrix.size() || 
               nextY >= matrix[0].size() || 
               matrix[nextX][nextY] > matrix[x][y] ||
               visited[nextX][nextY] == true)
                continue;
            
            char next = seas[nextX][nextY];
            if(next != 'A')
            {
                visited[nextX][nextY] = true;
                next = whichSea(matrix, nextX, nextY, seas, visited);
                visited[nextX][nextY] = false;
            }
            
            if(next != 'U')
            {
                if(next == 'A')
                    seas[x][y] = 'A';
                else if(seas[x][y] == 'U')
                    seas[x][y] = next;
                else if(seas[x][y] != next)
                    seas[x][y] = 'A';
            }
            
            if(seas[x][y] == 'A')
                break;
        }

        return seas[x][y];
    }
};
