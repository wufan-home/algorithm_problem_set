/*
   You are given an n x n 2D matrix representing an image.

   Rotate the image by 90 degrees (clockwise).
   
   Follow up: Could you do this in-place? 
*/

#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<vector<int> >& matrix) {
        if(matrix.size() == 0 ||
	   matrix[0].size() != matrix.size() ||
	   matrix.size() == 1)
		return;

	for(int l = 0, r = matrix.size() - 1; l <= r; ++l, --r)
	{
		vector<int> left_col;
		for(int col = l + 1; col < r; ++col)
		{
			//cout << matrix[col][l] << endl;
			left_col.push_back(matrix[col][l]);
			cout << left_col[col - l - 1] << endl;
		}

		cout << l << ", " << r << endl;
		for(int col = l + 1; col < r; ++col)
			cout << left_col[col] << ", ";
		cout << endl;
		
		int temp = matrix[l][l];
		matrix[l][l] = matrix[r][l];
		matrix[r][l] = matrix[r][r];
		matrix[r][r] = matrix[l][r];
		matrix[l][r] = temp;

		for(int i = l + 1; i < r; ++i)
		{
			matrix[i][l] = matrix[r][i];
			matrix[r][i] = matrix[r - i + l][r];
			matrix[r - i + l][r] = matrix[l][r - i + l];
			matrix[l][r - i + l] = left_col[i - l - 1];
		}	
	}
}

int main()
{
	// [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
	int r1[] = {1, 2, 3, 4, 5};
	int r2[] = {6,7,8,9,10};
	int r3[] = {11,12,13,14,15};	
	int r4[] = {16,17,18,19,20};
	int r5[] = {21,22,23,24,25};
	vector<vector<int> > m;
	m.push_back(vector<int>(r1, r1 + sizeof(r1) / sizeof(int)));
	m.push_back(vector<int>(r2, r2 + sizeof(r2) / sizeof(int)));
	m.push_back(vector<int>(r3, r3 + sizeof(r3) / sizeof(int)));
	m.push_back(vector<int>(r4, r4 + sizeof(r4) / sizeof(int)));
	m.push_back(vector<int>(r5, r5 + sizeof(r5) / sizeof(int)));
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			cout << m[i][j] << ", ";
		}
		cout << endl;
	}
	rotate(m);
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			cout << m[i][j] << ", ";
		}
		cout << endl;
	}
	return 1;
}
