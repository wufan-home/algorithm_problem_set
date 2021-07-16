/*
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
  For example, given n = 3, a solution set is:
  [
    "((()))",
    "(()())",
    "(())()",
    "()(())",
    "()()()"
  ]

  Solution: This is a recursion with two parameters, i.e., one is the num of left parenthesises,
  and the other one is the number of the right parenthesises. 
  If the two params are all equal to the number of patenthesis, the string is a valid one and put it into the result collection. 
  If the 1st param is larger than the given size, we got an invalid candidate and return without record it.
  Otherwise, notice that the 2nd param must be always smaller than the 1st one.
  Loop by adding ')' to the candidate string until the two params are equal and call the recursion function.

  Use an index cur to determine the writing poision.
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string valid(2 * n, '\0');
        generate(valid, 0, n, n, ans);
        return ans;
    }
    
private:
    void generate(string& valid, int cur, int left, int right, vector<string>& ans) {
        if (cur == valid.size()) {
            ans.push_back(valid);
            return;
        }
        
        if (left > 0) {
            valid[cur] = '(';
            generate(valid, cur + 1, left - 1, right, ans);
        }
        
        if (right > left) {
            valid[cur] = ')';
            generate(valid, cur + 1, left, right - 1, ans);
        }
    }
};
