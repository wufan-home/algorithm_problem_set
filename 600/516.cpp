/*
    Given a string s, find the longest palindromic subsequence's length in s. 
    You may assume that the maximum length of s is 1000.

    Example 1:
    Input:

    "bbbab"
    Output:
    4
    One possible longest palindromic subsequence is "bbbb".
    Example 2:
    Input:

    "cbbd"
    Output:
    2
    One possible longest palindromic subsequence is "bb".
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0)
            return 0;
        
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(int l = 1; l <= size; ++l)
        {
            for(int start = 0; start < size - l + 1; ++start)
            {
                int end = start + l - 1;
                
                if(l == 1)
                    dp[start][end] = 1;
                else if(l == 2)
                    dp[start][end] = s[start] == s[end] ? 2 : 1;
                else
                {
                    int middleMaxLen = (s[start] == s[end] ? 2 : 0) + dp[start + 1][end - 1];
                    dp[start][end] = max(middleMaxLen, max(dp[start + 1][end], dp[start][end - 1]));
                }
            }
        }
        
        return dp[0][size - 1];
    }
};
