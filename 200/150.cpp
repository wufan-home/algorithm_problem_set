/*
    Evaluate the value of an arithmetic expression in Reverse Polish Notation.
    Valid operators are +, -, *, /. Each operand may be an integer or another expression.
    Some examples:
      ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
      ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stackForNumbers;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if((tokens[i][0] >= '0' && tokens[i][0] <= '9') ||
                ((tokens[i][0] == '-' || tokens[i][0] == '+' ) && tokens[i].size() > 1))
                stackForNumbers.push(stoi(tokens[i]));
            else
            {
                const int right = stackForNumbers.top();
                stackForNumbers.pop();
                const int left = stackForNumbers.top();
                stackForNumbers.pop();
                stackForNumbers.push(calculate(left, right, tokens[i]));
            }
        }
        
        return stackForNumbers.top();
    }
    
private:
    string operators[4] = {"+", "-", "*", "/"};
    
    int calculate(const int left, const int right, const string& op)
    {
        if(op == operators[0])
            return left + right;
        else if(op == operators[1])
            return left - right;
        else if(op == operators[2])
            return left * right;
        else
            return left / right;
    }
};
