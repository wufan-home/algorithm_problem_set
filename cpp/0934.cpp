/*
    In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

    Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

    Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)



    Example 1:

    Input: A = [[0,1],[1,0]]
    Output: 1

    Example 2:

    Input: A = [[0,1,0],[0,0,0],[0,0,1]]
    Output: 2

    Example 3:

    Input: A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
    Output: 1



    Constraints:

        2 <= A.length == A[0].length <= 100
        A[i][j] == 0 or A[i][j] == 1


*/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        
        // Find the first island.
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (A[i][j] == 1) {
                    findIslandOutlayer(A, i, j, row, col, q);
                    found = true;
                    break;
                }
            }
            
            if (found) {
                break;
            }
        }
        
        // Find the shortest path.
        int res = 2;
        for (int size = q.size(); !q.empty(); --size) {
            if (size == 0) {
                ++res;
                size = q.size();
            }
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nextX = x + directions[i][0];
                int nextY = y + directions[i][1];
                if (!validPosition(nextX, nextY, row, col)) {
                    continue;
                }
                
                if (A[nextX][nextY] == 1) {
                    return res - 1;
                }
                
                if (A[nextX][nextY] == 0) {
                    A[nextX][nextY] = res;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
        
        return res - 1;
    }
    
private:
    static vector<vector<int>> directions;
    
    void findIslandOutlayer(vector<vector<int>>& A, int i, int j, int boundX, int boundY, queue<pair<int, int>>& q) {
        queue<pair<int, int>> qBFS;
        qBFS.push(make_pair(i, j));
        set<pair<int, int>> visited;
        while (!qBFS.empty()) {
            int x = qBFS.front().first;
            int y = qBFS.front().second;
            A[x][y] = -1;
            qBFS.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nextX = x + directions[i][0];
                int nextY = y + directions[i][1];
                if (!validPosition(nextX, nextY, boundX, boundY) || visited.count(make_pair(nextX, nextY)) != 0) {
                    continue;
                }
                
                if (A[nextX][nextY] == 1) {
                    qBFS.push(make_pair(nextX, nextY));
                }
                else if (A[nextX][nextY] == 0) {
                    q.push(make_pair(nextX, nextY));
                }
                
                visited.insert(make_pair(nextX, nextY));
            }
        }
    }
    
    bool validPosition(int x, int y, int boundX, int boundY) {
        return x >= 0 && x < boundX && y >= 0 && y < boundY; 
    }
};

vector<vector<int>> Solution::directions = vector<vector<int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
