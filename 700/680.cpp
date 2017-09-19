/*
    Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

    Example 1:
    Input: "aba"
    Output: True
    Example 2:
    Input: "abca"
    Output: True
    Explanation: You could delete the character 'c'.
    Note:
    The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        for(int l = 0, r = s.size() - 1; l < r; ++l, --r)
        {
            if(s[l] != s[r])
            {
                if(isParlindrome(s.substr(l + 1, r - l)) == false && 
                  isParlindrome(s.substr(l, r - l)) == false)
                    return false;
                
                break;
            }
        }
        
        return true;
    }
    
private:
    bool isParlindrome(const string &str)
    {
        for(int l = 0, r = str.size() - 1; l < r; ++l, --r)
        {
            if(str[l] != str[r])
                return false;
        }
        
        return true;
    }
};
