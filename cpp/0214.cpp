/*
    Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
    Find and return the shortest palindrome you can find by performing this transformation.

    For example:

    Given "aacecaaa", return "aaacecaaa".

    Given "abcd", return "dcbabcd".
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty())
            return s;

        string testS(s);
        testS.push_back('#');
        for(int i = s.size() - 1; i >= 0; --i)
            testS.push_back(s[i]);
            
        int oldSize = s.size();
        int newSize = testS.size();
        int end = oldSize - 1;
        for(; end >= 0; --end)
        {
            if(testS[end] != testS[newSize - 1])
                continue;
                
            bool found = true;
            int len = end + 1;
            for(int i = 0; i < len; ++i)
            {
                if(testS[i] != testS[newSize - len + i])
                {
                    found = false;
                    break;
                }
            }
            
            if(found)
                break;
        }
        
        string palindrome;
        for(int j = oldSize - 1; j > end; --j)
            palindrome.push_back(s[j]);
            
        palindrome.append(s);
        return palindrome;
    }
};
