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
        vector<string> results;
        string result;
        populateParenthesis(n, n, result, results);
        return results;
    }
    
private:
    void populateParenthesis(int l, int r, string result, vector<string>& results)
    {
        if(l == 0)
        {
            for(int i = 0; i < r; ++i)
                result.push_back(')');
                
            results.push_back(result);
        }
        else
        {
            result.push_back('(');
            populateParenthesis(l - 1, r, result, results);
            if(l < r)
            {
                result[result.size() - 1] = ')';
                populateParenthesis(l, r - 1, result, results);
            }
        }
    }
};
