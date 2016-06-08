/*
   Given a m x n matrix, if an element is 0, 
   set its entire row and column to 0. Do it in place.
   click to show follow up.
   Follow up:
   Did you use extra space?
   A straight forward solution using O(mn) space is probably a bad idea.
   A simple improvement uses O(m + n) space, but still not the best solution.
   Could you devise a constant space solution?
*/

#include <vector>

using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
	if(matrix.empty() || matrix[0].empty())
		return;

	int row = matrix.size();
	int col = matrix[0].size();
	bool set_first_row_zero = false;
	for(int i = 0; i < col; ++i)
	{
		if(matrix[0][i] == 0)
		{
			set_first_row_zero = true;
			break;
		}
	}

	bool set_first_col_zero = false;
	for(int i = 0; i < row; ++i)
	{
		if(matrix[i][0] == 0)
		{
			set_first_col_zero = true;
			break;
		}
	}

	for(int i = 1; i < row; ++i)
	{
		for(int j = 1; j < col; ++j)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i < row; ++i)
	{
		for(int j = 1; j < col; ++j)
		{
			if(matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}

	if(set_first_row_zero)
		for(int i = 0; i < col; matrix[0][i++] = 0) {}

	if(set_first_col_zero)
		for(int i = 0; i < row; matrix[i++][0] = 0) {}
}

/*
[[3,5,5,6,9,1,4,5,0,5],
 [2,7,9,5,9,5,4,9,6,8],
 [6,0,7,8,1,0,1,6,8,1],
 [7,2,6,5,8,5,6,5,0,6],
 [2,3,3,1,0,4,6,5,3,5],
 [5,9,7,3,8,8,5,1,4,3],
 [2,4,7,9,9,8,4,7,3,7],
 [3,5,2,8,8,2,2,4,9,8]]

[[0,0,0,0,0,0,0,0,0,0],
 [2,0,9,5,0,5,4,9,0,8],
 [0,0,0,0,0,0,0,0,0,0],
 [0,0,0,0,0,0,0,0,0,0],
 [0,0,0,0,0,0,0,0,0,0],
 [5,0,7,3,0,8,5,1,0,3],
 [2,0,7,9,0,8,4,7,0,7],
 [3,0,2,8,0,2,2,4,0,8]]

[[0,0,0,0,0,0,0,0,0,0],
 [2,0,9,5,0,0,4,9,0,8],
 [0,0,0,0,0,0,0,0,0,0],
 [0,0,0,0,0,0,0,0,0,0],
 [0,0,0,0,0,0,0,0,0,0],
 [5,0,7,3,0,0,5,1,0,3],
 [2,0,7,9,0,0,4,7,0,7],
 [3,0,2,8,0,0,2,4,0,8]]
*/
