/*
    Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

    Note: The input string may contain letters other than the parentheses ( and ).

    Examples:
    "()())()" -> ["()()()", "(())()"]
    "(a)())()" -> ["(a)()()", "(a())()"]
    ")(" -> [""]
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        dfs(s, 0, ')');
        return res;
    }
    
private:
    void dfs(string s, int last, char ch)
    {
        for(int i = 0, count = 0; i < s.size(); ++i)
        {
            if(s[i] != '(' && s[i] != ')')
                continue;
            
            if((count += s[i] == ch ? -1 : 1) >= 0)
                continue;
            
            for(int j = last; j <= i; ++j)
            {
                if(s[j] == ch && (j == last || s[j - 1] != ch))
                    dfs(s.substr(0, j) + s.substr(j + 1), j, ch);
            }
            
            return;
        }
        
        reverse(s.begin(), s.end());
        if(ch == ')')
        {
            dfs(s, 0, '(');
            return;
        }

        res.push_back(s);
    }
    
    vector<string> res;
};
