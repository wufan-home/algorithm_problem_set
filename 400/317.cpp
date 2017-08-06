/*
    You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
    You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

    Each 0 marks an empty land which you can pass by freely.
    Each 1 marks a building which you cannot pass through.
    Each 2 marks an obstacle which you cannot pass through.
    For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

    1 - 0 - 2 - 0 - 1
    |   |   |   |   |
    0 - 0 - 0 - 0 - 0
    |   |   |   |   |
    0 - 0 - 1 - 0 - 0
    The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

    Note:
    There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/

class Solution {
public:
    int steps[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0)
            return 0;
        
        int col = grid[0].size();
        if(col == 0)
            return 0;
        
        int minDist = INT_MAX;
        int buildingCount = 0;
        vector<vector<pair<int, int>>> board(row, vector<pair<int, int>>(col, make_pair(0, 0)));
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 1)
                {
                    ++buildingCount;
                    updateDistance(i, j, grid, board);
                }
            }
        }
        
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(board[i][j].second == buildingCount)
                    minDist = min(minDist, board[i][j].first);
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
    
private:
    void updateDistance(int x, int y, vector<vector<int>> &grid, vector<vector<pair<int, int>>> &board)
    {
        queue<pair<int, int>> q;

        vector<pair<int, int>> visited;
        
        q.push(make_pair(x, y));
        q.push(make_pair(-1, -1));
        int dist = 1;
        while(!q.empty())
        {
            int _x = q.front().first;
            int _y = q.front().second;
            q.pop();
            
            if(_x == -1)
            {
                ++dist;
                if(!q.empty())
                    q.push(make_pair(-1, -1));
                
                continue;
            }
            
            for(int i  = 0; i < 4; ++i)
            {
                int adjX = _x + steps[i][0];
                int adjY = _y + steps[i][1];

                pair<int, int> adj = make_pair(adjX, adjY);

                if(adjX < 0 || adjX >= grid.size() || adjY < 0 || adjY >= grid[0].size() || grid[adjX][adjY] > 0)
                    continue;

                if(find(visited.begin(), visited.end(), adj) != visited.end())
                    continue;

                board[adjX][adjY].first += dist;
                board[adjX][adjY].second += 1;
                q.push(adj);
                visited.push_back(adj);
            }
        }
    }
};
