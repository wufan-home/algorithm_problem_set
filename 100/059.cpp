/*
  Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

  For example,
  Given n = 3,
  You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
	vector<vector<int> > rv;
        if(n == 0)
		return rv;

	rv.resize(n, vector<int>(n, 1));
	int cur_value = 1;
	int steps = n /2;
	for(int i = 0; i < steps; ++i)
	{
		for(int j = i; j < n - i; ++j)
			rv[i][j] = cur_value++;

		for(int j = i + 1; j < n - 1 - i; ++j)
			rv[j][n - 1 - i] = cur_value++;

		for(int j = n - 1 - i; j >= i; --j)
			rv[n - 1 - i][j] = cur_value++;

		for(int j = n - 2 - i; j > i; --j)
			rv[j][i] = cur_value++;
	}

	if(n % 2)
		rv[steps][steps] = cur_value;

	return rv;
}

int main()
{
	vector<vector<int> > m;
	for(int n = 1; n < 5; ++n)
	{
		m.clear();
		m = generateMatrix(n);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				cout << m[i][j] << ", ";
			cout << endl;
		}
		cout << endl;
	}
	return 1;
}
