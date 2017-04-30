/*
    Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

    The input string does not contain leading or trailing spaces and the words are always separated by a single space.

    For example,
    Given s = "the sky is blue",
    return "blue is sky the".

    Could you do it in-place without allocating extra space?
*/

class Solution {
public:
    void reverseWords(string &s) {
        for(int i = 0; i < s.size();)
        {
            if(s[i] == ' ')
            {
                ++i;
                continue;
            }
            
            int start = i;
            int end = i;
            for(; end < s.size() && s[end] != ' '; ++end) {}
            i = end--;
            
            for(; start < end; ++start, --end)
                swap(s[start], s[end]);
        }
        
        for(int start = 0, end = s.size() - 1; start < end; ++start, --end)
            swap(s[start], s[end]);
    }
};
