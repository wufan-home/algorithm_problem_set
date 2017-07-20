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

class Solution
{
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));

	int bound = n / 2;
	int current = 1;
	for(int i = 0; i <= bound; ++i)
	{
	    if(i == bound)
	    {
		if(n % 2 == 1)
		    matrix[i][i] = n * n;

		continue;
	    }

	    for(int j = i; j < n - i; ++j)
		matrix[i][j] = current++;

	    for(int j = i + 1; j < n - i - 1; ++j)
		matrix[j][n - i - 1] = current++;

	    for(int j = n - i - 1; j >= i; --j)
		matrix[n - i - 1][j] = current++;

	    for(int j = n - i - 2; j > i; --j)
		matrix[j][i] = current++;
	}

	return matrix;
    }
};
