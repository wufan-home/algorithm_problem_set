/*
    Given a picture consisting of black and white pixels, find the number of black lonely pixels.

    The picture is represented by a 2D char array consisting of 'B' and 'W', 
    which means black and white pixels respectively.

    A black lonely pixel is character 'B' that located at a specific position 
    where the same row and same column don't have any other black pixels.

    Example:
    Input: 
    [['W', 'W', 'B'],
     ['W', 'B', 'W'],
     ['B', 'W', 'W']]

    Output: 3
    Explanation: All the three 'B's are black lonely pixels.
    Note:
    The range of width and height of the input 2D array is [1,500].
*/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size();
        if(row == 0)
            return 0;
        
        int col = picture[0].size();
        if(col == 0)
            return 0;
        
        int count = 0;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                bool conflict = false;
                if(picture[i][j] == 'B')
                {
                    for(int k = 0; k < col; ++k)
                    {
                        if(k != j && (picture[i][k] == 'B' || picture[i][k] == 'N'))
                        {
                            conflict = true;
                            picture[i][k] = 'N';
                        }
                    }
                    
                    for(int k = 0; k < row; ++k)
                    {
                        if(k != i && (picture[k][j] == 'B' || picture[k][j] == 'N'))
                        {
                            conflict = true;
                            picture[k][j] = 'N';
                        }
                    }
                    
                    if(conflict)
                        picture[i][j] = 'N';
                    else
                        ++count;
                }
            }
        }
        
        return count;
    }
};
