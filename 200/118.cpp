/*
  Given numRows, generate the first numRows of Pascal's triangle.

  For example, given numRows = 5,
  Return

  [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangles;
        if(numRows >= 1)
            triangles.push_back(vector<int>(1, 1));
            
        if(numRows >= 2)
            triangles.push_back(vector<int>(2, 1));
            
        if(numRows >= 3)
        {
            for(int i = 3; i <= numRows; ++i)
            {
                triangles.push_back(vector<int>(i, 1));
                vector<int>& prev = triangles[triangles.size() - 2];
                vector<int>& last = triangles[triangles.size() - 1];
                for(int j = 1; j < i - 1; ++j)
                    last[j] = prev[j - 1] + prev[j];
            }
        }
        
        return triangles;
    }
};
