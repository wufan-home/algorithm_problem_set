/*
    Find the length of the longest substring T of a given string (consists of lowercase letters only) 
    such that every character in T appears no less than k times.

    Example 1:

    Input:
    s = "aaabb", k = 3

    Output:
    3

    The longest substring is "aaa", as 'a' is repeated 3 times.
    Example 2:

    Input:
    s = "ababbc", k = 2

    Output:
    5

    The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty())
            return k == 0;
        
        int maxLen = 0;
        int size = s.size();
        for(int i = 0; i <= size - k;)
        {
            int count[26] = {0};
            int mask = 0;
            int maxLenIndex = i;
            for(int j = i; j < size; ++j)
            {
                int t = s[j] - 'a';
                if(++count[t] < k)
                    mask |= (1 << t);
                else
                    mask &= (~(1 << t));
                
                if(mask == 0)
                {
                    maxLen = max(maxLen, j - i + 1);
                    maxLenIndex = j;
                }
            }
            
            i = maxLenIndex + 1;
        }
        
        return maxLen;
    }
};
