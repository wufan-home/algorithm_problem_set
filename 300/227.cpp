#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>

using namespace std;

int calculate(string s) {
        if(s.empty())
		return INT_MIN;

	int rv = 0;
	int cache = 1;
	int cur_op_1 = 1;
	int prev_op_1 = 1;
	int cur_op_2 = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		if(isdigit(s[i]))
		{
			int num = 0;
			for(; i < s.size() && isdigit(s[i]); ++i)
				num = num * 10 + s[i] - '0';
			--i;
			if(cur_op_2 == 0)
				cache = num;
			else if(cur_op_2 == 1)
				cache *= num;
			else if(cur_op_2 == -1)
				cache /= num;
		}
		else if(s[i] == '+' || s[i] == '-')
		{
			prev_op_1 = cur_op_1;
			cur_op_1 = (s[i] == '+' ? 1 : -1);
			rv += prev_op_1 * cache;
			cur_op_2 = 0;
		}
		else if(s[i] == '*')
			cur_op_2 = 1;
		else if(s[i] == '/')
			cur_op_2 = -1;
	}

	return rv += cur_op_1 * cache;
}

int main()
{
	cout << calculate("5 + 1 / 2") << endl;
	cout << calculate("3 * 4") << endl;
	cout << calculate("1*2-3/4+5*6-7*8+9/10") << endl;
	return 1;
}
