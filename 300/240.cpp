/*
  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

  Integers in each row are sorted in ascending from left to right.
  Integers in each column are sorted in ascending from top to bottom.
  For example,

  Consider the following matrix:
  
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

  Solution:
  Starting from the right-upmost emtry, we compare the value with the target.
  if it is equal to the target, we found an entry equal to the target and then return true.
  If it is smaller than the target, move to the entry of the same column and in the next row.
  If it is bigger, move to the entry of the same row and the previous column.

  The reason why we choose the right-upmost is because the changing direections of row and column from this point are different.
*/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
		return false;

	int row = 0;
	int col = matrix[0].size() - 1;
	for(; row < matrix.size() && col >= 0;)
	{
		if(matrix[row][col] == target)
			return true;
		else if(matrix[row][col] < target)
			++row;
		else
			--col;
	}

	retrun false;
}
