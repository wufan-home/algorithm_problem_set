/*
    Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, 
    where in each step you can delete one character in either string.

    Example 1:
    Input: "sea", "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
    Note:
    The length of given words won't exceed 500.
    Characters in given words can only be lower-case letters.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty())
            return word2.size();
        
        if(word2.empty())
            return word1.size();
        
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        
        for(int i = 1; i <= l1; ++i)
        {
            for(int j = 1; j <= l2; ++j)
                dp[i][j] = max(word1[i - 1] == word2[j - 1] ? 1 + dp[i - 1][j - 1] : 0, 
                               max(dp[i - 1][j], dp[i][j - 1]));
        }
        
        return word1.size() + word2.size() - 2 * dp[l1][l2];
    }
};
