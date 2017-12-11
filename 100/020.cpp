/*
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
  determine if the input string is valid.
  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> opToValue;
        opToValue['('] = 1;
        opToValue[')'] = -1;
        opToValue['['] = 2;
        opToValue[']'] = -2;
        opToValue['{'] = 3;
        opToValue['}'] = -3;
        
        stack<int> st;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(opToValue[s[i]]);
            else
            {
                if(st.empty() || opToValue[s[i]] + st.top() != 0)
                    return false;
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};
