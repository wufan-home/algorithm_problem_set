#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

int maximalRectangle(vector<vector<char> >& matrix) {
	if(matrix.empty() || matrix[0].empty())
		return 0;

	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int> > heights(row, vector<int>(col, 0));
	for(int c = 0; c < col; ++c)
	{
		for(int r = 0; r < row; ++r)
		{
			if(matrix[r][c] == '1')
				heights[r][c] = (r == 0 ? 1 : heights[r - 1][c] + 1);
		}
	}

	int max_area = 0;
	for(int r = 0; r < row; ++r)
	{
		stack<pair<int, int> > wh_stack;
		for(int c = 0; c <= col; ++c)
		{
			int least_h = (c == col ? 0 : heights[r][c]);
			int width = 0;
			int height = 0;
			while(!wh_stack.empty() && wh_stack.top().second >= least_h)
			{
				width += wh_stack.top().first;
				height = wh_stack.top().second;
				wh_stack.pop();
				max_area = max(max_area, width * height);
			}
			if(c < col && heights[r][c])
				max_area = max(max_area, heights[r][c] * (++width));
			wh_stack.push(make_pair(width, heights[r][c]));
		}
	}

	return max_area;
}

int main()
{
	//["01101","11010","01110","11110","11111","00000"]
	//["1010","1011","1011","1111"]
	vector<vector<char> > matrix;
	matrix.push_back(vector<char>(5, '1'));
	matrix[0][0] = '0';
	matrix[0][3] = '0';
	matrix.push_back(vector<char>(5, '1'));
	matrix[1][2] = '0';
	matrix[1][4] = '0';
	matrix.push_back(vector<char>(5, '1'));
	matrix[2][0] = '0';
	matrix[2][4] = '0';
	matrix.push_back(vector<char>(5, '1'));
	matrix[3][4] = '0';
	matrix.push_back(vector<char>(5, '1'));
	matrix.push_back(vector<char>(5, '0'));
	cout << maximalRectangle(matrix) << endl;
	return 1;
}
