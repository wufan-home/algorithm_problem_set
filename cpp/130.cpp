/*
  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
  A region is captured by flipping all 'O's into 'X's in that surrounded region.
  For example,
  X X X X
  X O O X
  X X O X
  X O X X
  After running your function, the board should be:
  X X X X
  X X X X
  X X X X
  X O X X
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
            
        for(int i = 0; i < board.size(); ++i)
        {
            if(board[i][0] == 'O')
                exploreRegion(board, i, 0);
                
            if(board[i][board[0].size() - 1] == 'O')
                exploreRegion(board, i, board[0].size() - 1);
        }
        
        for(int i = 0; i < board[0].size(); ++i)
        {
            if(board[0][i] == 'O')
                exploreRegion(board, 0, i);
                
            if(board[board.size() - 1][i] == 'O')
                exploreRegion(board, board.size() - 1, i);
        }

        for(int i = 1; i < board.size() - 1; ++i)
        {
            for(int j = 1; j < board[0].size() - 1; ++j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }
private:
    void exploreRegion(vector<vector<char>>& board, int r, int c)
    {
        board[r][c] = 'Y';
        queue<pair<int, int>> queueForCoordinates;
        queueForCoordinates.push(make_pair(r, c));
        while(!queueForCoordinates.empty())
        {
            int x = queueForCoordinates.front().first;
            int y = queueForCoordinates.front().second;
            queueForCoordinates.pop();
            
            for(int i = 0; i < 4; ++i)
            {
                if(x + step[i][0] < 0 || x + step[i][0] >= board.size())
                    continue;
                    
                if(y + step[i][1] < 0 || y + step[i][1] >= board[0].size())
                    continue;
                    
                if(board[x + step[i][0]][y + step[i][1]] == 'O')
                {
                    board[x + step[i][0]][y + step[i][1]] = 'Y';
                    queueForCoordinates.push(make_pair(x + step[i][0], y + step[i][1]));
                }
            }
        }
    }
    
    int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
