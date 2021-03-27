/*
    Given a string, 
    you need to reverse the order of characters in each word within a sentence 
    while still preserving whitespace and initial word order.
    Example 1:
    Input: "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"
    Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

class Solution {
public:
    string reverseWords(string s) {
        string reverse_string;
        stack<char> stack_for_char;
        
        for(int i = 0; i < s.size();)
        {
            if(s[i] != ' ')
            {
                int cur = i;
                for(; cur < s.size() && s[cur] != ' '; ++cur)
                    stack_for_char.push(s[cur]);
                    
                i = cur;
            }
            else 
            {
                reverse_string.push_back(' ');
                ++i;
            }
            
            for(; !stack_for_char.empty(); stack_for_char.pop())
                reverse_string.push_back(stack_for_char.top());
        }
        
        return reverse_string;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.size();)
        {
            if(s[i] != ' ')
            {
                int start = i;
                int end = i;
                for(; end < s.size() && s[end] != ' '; ++end) { }
                i = end--;
                for(; start < end; ++start, --end)
                    swap(s[start], s[end]);
            }
            else
                ++i;
        }
        
        return s;
    }
};
