/*
	Implement a basic calculator to evaluate a simple expression string.

	The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

	You may assume that the given expression is always valid.

	Some examples:
	"3+2*2" = 7
	" 3/2 " = 1
	" 3+5 / 2 " = 5
	Note: Do not use the eval built-in library function.
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> stackForNumbers;
        stack<char> stackForOperations;
        
        for(int i = 0; i < s.size();)
        {
            if(s[i] == ' ')
                ++i;
            else if(s[i] >= '0' && s[i] <= '9')
                stackForNumbers.push(getNumber(s, i));
            else 
                cleanStack(stackForNumbers, stackForOperations, s[i++]);
        }
        
        cleanStack(stackForNumbers, stackForOperations, '+');
        return stackForNumbers.top();
    }
    
private:
    void cleanStack(stack<int>& stackForNumbers, stack<char>& stackForOperations, char lastOp)
    {
        while(1)
        {
            if(stackForOperations.empty() || getOperatorPriority(lastOp) > getOperatorPriority(stackForOperations.top()))
                break;
                
            int r = stackForNumbers.top();
            stackForNumbers.pop();
            
            int l = stackForNumbers.top();
            stackForNumbers.pop();
            
            char op = stackForOperations.top();
            stackForOperations.pop();
            
            stackForNumbers.push(doSimpleCalculation(l, r, op));
        }
        
        stackForOperations.push(lastOp);
    }

    int getOperatorPriority(char op)
    {
        if(op == '+' || op == '-')
            return 1;
        else
            return 2;
    }
    
    int getNumber(const string& s, int& start)
    {
        int value = 0;
        for(; start < s.size() && s[start] >= '0' && s[start] <= '9'; ++start)
            value = value * 10 + s[start] - '0';
            
        return value;
    }
    
    int doSimpleCalculation(int l, int r, char op)
    {
        if(op == '+')
            return l + r;
        else if(op == '-')
            return l - r;
        else if(op == '*')
            return l * r;

        return l / r;
    }
};
