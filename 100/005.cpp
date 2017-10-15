/*
	Given a string S, find the longest palindromic substring in S. 
	You may assume that the maximum length of S is 1000, 
	and there exists one unique longest palindromic substring.
	
	1. DP method: This is a typical to solve the questions about palingdromes.
	2. Manacher's Algorithm.
*/

// DP
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        
        int size = s.size();
        bool dp[size][size] = {false};
        int start = 0;
        int maxLen = 0;
        for(int len = 1; len <= size; ++len)
        {
            for(int i = 0; i < size - len + 1; ++i)
            {
                if(s[i] == s[i + len - 1] && (len <= 2 || dp[i + 1][i + len - 2]))
                {
                    dp[i][i + len - 1] = true;
                    if(len > maxLen)
                    {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
