/*
    Given a non-empty string check if it can be constructed by taking a substring of it 
    and appending multiple copies of the substring together. 
    You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

    Example 1:
    Input: "abab"

    Output: True

    Explanation: It's the substring "ab" twice.
    Example 2:
    Input: "aba"

    Output: False
    Example 3:
    Input: "abcabcabcabc"

    Output: True

    Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() < 2)
            return false;
        
        int size = s.size();
        int bound = s.size() / 2;
        for(int len = 1; len <= bound; ++len)
        {
            if(s.size() % len != 0)
                continue;
            
            string candidate = s.substr(0, len);
            int duplicate = true;
            for(int i = 0; i < size; i += len)
            {
                if(s.substr(i, len) != candidate)
                {
                    duplicate = false;
                    break;
                }
            }
                
            if(duplicate)
                return true;
        }
        
        return false;
    }
};
