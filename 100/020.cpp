#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
        if(s.empty() || s.size() % 2 != 0)
		return false;

	unordered_map<char, int> op_to_int;
	op_to_int['('] = 1;
	op_to_int[')'] = -1;
	op_to_int['['] = 2;
	op_to_int[']'] = -2;
	op_to_int['{'] = 3;
	op_to_int['}'] = -3;
	stack<int> op_stack;
	for(int i = 0; i < s.size(); ++i)
	{
		int weight = op_to_int[s[i]];
		if(weight > 0)
			op_stack.push(weight);
		else
		{
			if(op_stack.empty() || weight + op_stack.top() != 0)
				return false;

			op_stack.pop();
		}
	}

	return op_stack.empty();
}

int main()
{
	return 1;
}
