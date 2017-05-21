/*
    Given a string S and a string T, count the number of distinct subsequences of T in S.

    A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

    Here is an example:
    S = "rabbbit", T = "rabbit"

    Return 3.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if(lenS < lenT)
            return 0;
            
        vector<vector<int>> partialMatch(lenT + 1, vector<int>(lenS + 1, 0));
        for(int i = 0; i <= lenS; ++i)
            partialMatch[0][i] = 1;
            
        for(int r = 1; r <= lenT; ++r)
        {
            for(int c = r; c <= lenS; ++c)
                partialMatch[r][c] = partialMatch[r][c - 1] + (s[c - 1] == t[r - 1] ? partialMatch[r - 1][c - 1] : 0);
        }
        
        return partialMatch[lenT][lenS];
    }
};
