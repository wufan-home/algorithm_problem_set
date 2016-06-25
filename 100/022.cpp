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

void Generate(string& result, int cur, int l_count, int r_count, int n, vector<string>& results)
{
        if(cur == result.size())
            results.push_back(result);
        else if(l_count < n)
        {
            result[cur++] = '(';
	    ++l_count;
            for(; r_count <= l_count; ++r_count)
            {
                Generate(result, cur, l_count, r_count, n, results);
                result[cur++] = ')';
            }
        }
}
    
vector<string> generateParenthesis(int n) {
        vector<string> results;
        if(n == 0)
            return results;
            
        string result(2 * n, '\0');
        Generate(result, 0, 0, 0, n, results);
        return results;
}
