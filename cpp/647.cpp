/*
    Given a string, your task is to count how many palindromic substrings in this string.

    The substrings with different start indexes or end indexes are counted as different substrings 
    even they consist of same characters.

    Example 1:
    Input: "abc"
    Output: 3
    Explanation: Three palindromic strings: "a", "b", "c".
    Example 2:
    Input: "aaa"
    Output: 6
    Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
    Note:
    The input string length won't exceed 1000.
*/

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() < 2)
            return s.size();
        
        int count = 0;
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for(int i = size - 1; i >= 0; --i)
        {
            for(int j = i; j < size; ++j)
            {
                if(j == i)
                    dp[i][j] = true;
                else if(j == i + 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && (i + 1 == j - 1 || dp[i + 1][j - 1]));
                
                count += (int)dp[i][j];
            }
        }
        
        return count;
    }
};
