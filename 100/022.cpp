#include <string>
#include <vector>
#include <iostream>

using namespace std;

void GenerateAux(int left, int right, int n, string str, vector<string>& rv)
{
	if(right == n)
	{
		rv.push_back(str);
		return;
	}

	if(left < n)
	{
		str.push_back('(');
		for(int i = 0; right + i <= left + 1; ++i)
		{
			GenerateAux(left + 1, right + i, n, str, rv);
			str.push_back(')');
		}
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> rv;
	if(n == 0)
		return rv;

	string str("");
	GenerateAux(0, 0, n, str, rv);
	return rv;
}

int main()
{
	for(int i = 3; i <= 3; ++i)
	{
		cout << "Case " << i << ": " << endl;
		vector<string> rv = generateParenthesis(i);
		for(int i = 0; i < rv.size(); ++i)
			cout << rv[i] << endl;
	}

	return 1;
}
