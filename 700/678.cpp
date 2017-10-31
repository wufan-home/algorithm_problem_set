/*
    Given a string containing only three types of characters: '(', ')' and '*', 
    write a function to check whether this string is valid. We define the validity of a string by these rules:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
    An empty string is also valid.
    Example 1:
    Input: "()"
    Output: True
    Example 2:
    Input: "(*)"
    Output: True
    Example 3:
    Input: "(*))"
    Output: True
    Note:
    The string size will be in the range [1, 100].
*/

class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        stack<int> left;
        stack<int> star;
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == '(')
                left.push(i);
            else if(s[i] == '*')
                star.push(i);
            else if(!left.empty())
                left.pop();
            else if(!star.empty())
                star.pop();
            else
                return false;
        }
        
        while(!left.empty())
        {
            if(!star.empty() && left.top() < star.top())
            {
                left.pop();
                star.pop();
            }
            else
                break;
        }
        
        return left.empty();
    }
};  
