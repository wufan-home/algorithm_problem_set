/*
    Given a string s of '(' , ')' and lowercase English characters. 

    Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

    Formally, a parentheses string is valid if and only if:

        It is the empty string, contains only lowercase characters, or
        It can be written as AB (A concatenated with B), where A and B are valid strings, or
        It can be written as (A), where A is a valid string.



    Example 1:

    Input: s = "lee(t(c)o)de)"
    Output: "lee(t(c)o)de"
    Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

    Example 2:

    Input: s = "a)b(c)d"
    Output: "ab(c)d"

    Example 3:

    Input: s = "))(("
    Output: ""
    Explanation: An empty string is also valid.

    Example 4:

    Input: s = "(a(b(c)d)"
    Output: "a(b(c)d)"



    Constraints:

        1 <= s.length <= 10^5
        s[i] is one of  '(' , ')' and lowercase English letters.

*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.size();
        string res;
        list<int> left_paren_index_stack;
        
        int cur = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] != '(' && s[i] != ')' && left_paren_index_stack.empty()) {
                res.push_back(s[i]);
            }
            else if (s[i] == '(') {
                left_paren_index_stack.push_back(i);
            } 
            else if (s[i] == ')') { 
                if (!left_paren_index_stack.empty()) {
                    if (left_paren_index_stack.size() == 1) {
                        for (int j = left_paren_index_stack.back(); j <= i; ++j) {
                            res.push_back(s[j]);
                        }
                    }

                    left_paren_index_stack.pop_back();
                }
            }
        }
        
        while (!left_paren_index_stack.empty()) {
            int start = left_paren_index_stack.front();
            left_paren_index_stack.pop_front();
            int end = left_paren_index_stack.empty() ? len : left_paren_index_stack.front();
            for (int i = start + 1; i < end; ++i) {
                res.push_back(s[i]);
            }
        }
        
        return res;
    }
};
