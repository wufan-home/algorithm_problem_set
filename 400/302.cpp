/*
    An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. 
    The black pixels are connected, i.e., there is only one black region. 
    Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, 
    return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

    For example, given the following image:

    [
      "0010",
      "0110",
      "0100"
    ]
    and x = 0, y = 2,
    Return 6.


*/

class Solution {
public:
    int steps[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        int upper = x;
        int lower = x;
        int left = y;
        int right = y;
        
        if(image.empty() || image[0].empty())
            return 0;
        
        int row = image.size();
        int col = image[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while(!q.empty())
        {
            int _x = q.front().first;
            int _y = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; ++i)
            {
                int nextX = _x + steps[i][0];
                int nextY = _y + steps[i][1];
                
                if(nextX < 0 || nextX >= row || nextY < 0 || nextY >= col || 
                   image[nextX][nextY] == '0' || 
                   visited[nextX][nextY] == true)
                    continue;
                
                visited[nextX][nextY] = true;
                
                upper = min(upper, nextX);
                lower = max(lower, nextX);
                left = min(left, nextY);
                right = max(right, nextY);
                
                q.push(make_pair(nextX, nextY));
            }
        }
        
        
        
        return (lower - upper + 1) * (right - left + 1);
    }
};
