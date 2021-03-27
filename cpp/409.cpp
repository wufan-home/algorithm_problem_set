/*
    Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

    This is case sensitive, for example "Aa" is not considered a palindrome here.

    Note:
    Assume the length of given string will not exceed 1,010.

    Example:

    Input:
    "abccccdd"

    Output:
    7

    Explanation:
    One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;
        for(int i = 0; i < s.size(); ++i)
        {
            if(charCount.find(s[i]) == charCount.end())
                charCount[s[i]] = 0;
                
            ++charCount[s[i]];
        }
        
        int hasSingleChar = 0;
        int totalSize = 0;
        for(unordered_map<char, int>::iterator it = charCount.begin(); it != charCount.end(); ++it)
        {
            hasSingleChar = hasSingleChar == 0 ? it->second % 2 : hasSingleChar;
            totalSize += it->second - (it->second % 2);
        }
        
        return totalSize + hasSingleChar;
    }
};
