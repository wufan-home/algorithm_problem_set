/*
  Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

  For example,
  Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix)
{
	vector<int> rv;
        int row = matrix.size();
	int col = matrix[0].size();
	if(row == 0 || col == 0)
		return rv;

	int steps = min(row, col) / 2;

	for(int i = 0; i < steps; ++i)
	{
		for(int j = i; j < col - i; ++j)
			rv.push_back(matrix[i][j]);

		for(int j = i + 1; j < row - i - 1; ++j)
			rv.push_back(matrix[j][col - i - 1]);

		for(int j = col - i - 1; j >= i; --j)
			rv.push_back(matrix[row - i - 1][j]);

		for(int j = row - i - 2; j > i; --j)
			rv.push_back(matrix[j][i]);
	}

	if(min(row, col) % 2 == 1)
	{
		if(row >= col)
		{
			for(int i = steps; i < row - steps; ++i)
				rv.push_back(matrix[i][steps]);
		}
		else
		{
			for(int i = steps; i < col - steps; ++i)
				rv.push_back(matrix[steps][i]);
		}
	}

	return rv;
}

int main()
{
	vector<vector<int> > m({vector<int>({1}), vector<int>({1}), vector<int>({1}), vector<int>({1})});
	vector<int> rv = spiralOrder(m);
	for(int i = 0; i < rv.size(); ++i)
		cout << rv[i] << ", ";
	cout << endl;
	return 1;
}

