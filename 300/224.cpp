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
