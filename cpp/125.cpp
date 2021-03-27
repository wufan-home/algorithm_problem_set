/*
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
  For example,
  "A man, a plan, a canal: Panama" is a palindrome.
  "race a car" is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        for(int l = 0, r = s.size() - 1; l < r;)
        {
            if(!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9')))
                ++l;
            else if(!((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9')))
                --r;
            else 
            {
                int lvalue = s[l] - (int)(s[l] >= 'a' && s[l] <= 'z' ? 'a' : 'A');
                int rvalue = s[r] - (int)(s[r] >= 'a' && s[r] <= 'z' ? 'a' : 'A');
                if(lvalue != rvalue)
                    return false;
                    
                ++l;
                --r;
            }
        }
        
        return true;
    }
};
