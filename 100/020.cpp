/*
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
  determine if the input string is valid.
  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stackForLeftParentheses.push(s[i]);
            else if(!checkMatchedParentheses(s[i]))
                    return false;
        }
        
        return stackForLeftParentheses.empty();
    }
private:
    stack<char> stackForLeftParentheses;

    bool checkMatchedParentheses(const char rightParentheses)
    {
        if(stackForLeftParentheses.empty() || 
           ((int) stackForLeftParentheses.top() != (int) rightParentheses - 1 && 
           (int) stackForLeftParentheses.top() != (int) rightParentheses - 2))
            return false;
        
        stackForLeftParentheses.pop();
        return true;
    }
};
