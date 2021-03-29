/*
   Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
            
        if(s1.empty())
            return s2 == s3;
            
        if(s2.empty())
            return s1 == s3;
            
        int lenS1 = s1.size();
        int lenS2 = s2.size();
        vector<vector<bool>> interleaveMatrix(lenS1 + 1, vector<bool>(lenS2 + 1, false));
        for(int r = 0; r <= lenS1; ++r)
        {
            for(int c = 0; c <= lenS2; ++c)
            {
                if(r == 0 && c == 0)
                    interleaveMatrix[0][0] = true;
                else if(r == 0)
                    interleaveMatrix[r][c] = (s2[c - 1] == s3[c - 1] && interleaveMatrix[r][c - 1]);
                else if(c == 0)
                    interleaveMatrix[r][c] = (s1[r - 1] == s3[r - 1] && interleaveMatrix[r - 1][c]);
                else
                    interleaveMatrix[r][c] = (s1[r - 1] == s3[r + c - 1] && interleaveMatrix[r - 1][c]) || 
                                             (s2[c - 1] == s3[r + c - 1] && interleaveMatrix[r][c - 1]);
            }
        }
        
        return interleaveMatrix[lenS1][lenS2];
    }
};
