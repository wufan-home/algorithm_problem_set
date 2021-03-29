/*
	Given an input string, reverse the string word by word.

	For example,
	Given s = "the sky is blue",
	return "blue is sky the".

	Update (2015-02-12):
	For C programmers: Try to solve it in-place in O(1) space.

	click to show clarification.

	Clarification:
	What constitutes a word?
	A sequence of non-space characters constitutes a word.
	Could the input string contain leading or trailing spaces?
	Yes. However, your reversed string should not contain leading or trailing spaces.
	How about multiple spaces between two words?
	Reduce them to a single space in the reversed string.
*/

class Solution {
public:
    void reverseWords(string &s) {
        for(; s.size() > 0 && s[0] == ' '; s.erase(0, 1)) {}
        for(; s.size() > 0 && s[s.size() - 1] == ' '; s.pop_back()) {}
        
        for(int i = 0; i < s.size();)
        {
            if(s[i] == ' ')
            {
                for(++i; i < s.size() && s[i] == ' '; s.erase(i, 1)) {}
                continue;
            }
                
            int start = i;
            int end = i;
            for(; end + 1 < s.size() && s[end + 1] != ' '; ++end) {}
            i = end + 1;
            
            for(; start < end; ++start, --end)
                swap(s[start], s[end]);
        }
        
        for(int start = 0, end = s.size() - 1; start < end; ++start, --end)
            swap(s[start], s[end]);
    }
};
