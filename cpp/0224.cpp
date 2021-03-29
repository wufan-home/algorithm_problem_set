/*
	Implement a basic calculator to evaluate a simple expression string.

	The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

	You may assume that the given expression is always valid.

	Some examples:
	"1 + 1" = 2
	" 2-1 + 2 " = 3
	"(1+(4+5+2)-3)+(6+8)" = 23
	Note: Do not use the eval built-in library function.
*/

class Solution {
public:
	// Recursive.
    int calculate(string s) {
        if(s.empty())
            return INT_MIN;
          
        int value = 0;
        char op = '+';
        for(int i = 0; i < s.size();)
        {
            if(s[i] == ' ')
                ++i;
            else if(s[i] >= '0' && s[i] <= '9')
                value = value + (op == '+' ? 1 : -1) * getNumber(s, i);
            else if(s[i] == '+' || s[i] == '-')
                op = s[i++];
            else if(s[i] == '(')
                value = value + (op == '+' ? 1 : -1) * calculateByIndex(s, ++i);
        }
        
        return value;
    }
    
private:
    int calculateByIndex(const string& s, int& index)
    {
        int value = 0;
        char op = '+';
        for(; index < s.size() && s[index] != ')';)
        {
            if(s[index] == ' ')
                ++index;
            else if(s[index] >= '0' && s[index] <= '9')
                value = value + (op == '+' ? 1 : -1) * getNumber(s, index);
            else if(s[index] == '+' || s[index] == '-')
                op = s[index++];
            else if(s[index] == '(')
                value = value + (op == '+' ? 1 : -1) * calculateByIndex(s, ++index);
        }

        ++index;
        return value;
    }

    int getNumber(const string& s, int& index)
    {
        int value = 0;
        for(; index < s.size() && s[index] >= '0' && s[index] <= '9'; ++index)
            value = 10 * value + s[index] - '0';
        
        return value;
    }
};

#include <iostream>
#include <string>
#include <stack>
#include <climits>
#include <ctype.h>

using namespace std;

int calculate(string s)
{
	if(s.empty())
		return INT_MIN;

	int size = s.size();
	int rv = 0;

	int cur_op = 1;
	stack<int> op_stack;
	op_stack.push(1);
	for(int i = 0; i < size; ++i)
	{
		if(isdigit(s[i]))
		{
			int num = 0;
			for(; i < size && isdigit(s[i]); ++i)
				num = 10 * num + s[i] - '0';
			--i;
			rv += cur_op * num;
		}
		else if(s[i] == '+' || s[i] == '-')
			cur_op = (s[i] == '+' ? 1 : -1) * op_stack.top();
		else if(s[i] == '(')
			op_stack.push(cur_op);
		else if(s[i] == ')')
			op_stack.pop();
	}

	return rv;
}

int main()
{
	//cout << "1 + (2 + 3) = 6 == "<< calculate("1 + (2 + 3)") << endl ;
	//cout << "3 - (4 + 5) = -6 == " << calculate("3 - (4 + 5)") << endl ;
	//cout << "3 - (4 + (5 + 6)) = -12 == " << calculate("3 - (4 + (5 + 6))") << endl ;
	//cout << "3 - (4 - (5 + 6)) = 10 == " << calculate("3 - (4 - (5 + 6))") << endl ;
	cout << "3 - ((5 - 6) - 4) = 8 == " << calculate("3 - ((5 - 6) - 4)") << endl ;
	//cout << "3 - (4 - (5 - (7 + 6))) = -9 == " << calculate("3 - (4 - (5 - (7 + 6)))") << endl ;
}
