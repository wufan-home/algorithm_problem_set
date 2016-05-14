#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

void findPathLength(const vector<vector<int> >& matrix,
		    int r, int c, vector<vector<int> >& mem,
		    int current_len, int& max_len)
{
	if(mem[r][c] != -1)
	{
		current_len += mem[r][c];
		if(max_len == 0 || current_len > max_len)
			max_len = current_len;
		return;
	}

	bool found_new_node = false;
	
	if(r - 1 >= 0 && matrix[r - 1][c] > matrix[r][c])
	{
		findPathLength(matrix, r - 1, c, mem, current_len, max_len);
		found_new_node = true;
	}

	if(c - 1 >= 0 && matrix[r][c - 1] > matrix[r][c])
	{
		findPathLength(matrix, r, c - 1, mem, current_len, max_len);
		found_new_node = true;
	}

	if(r + 1 < matrix.size() && matrix[r + 1][c] > matrix[r][c])
	{
		findPathLength(matrix, r + 1, c, mem, current_len, max_len);
		found_new_node = true;
	}

	if(c + 1 >= 0 && matrix[r][c + 1] > matrix[r][c])
	{
		findPathLength(matrix, r, c + 1, mem, current_len, max_len);
		found_new_node = true;
	}

	if(!found_new_node)
	{
		if(max_len == 0 || current_len > max_len)
			max_len = current_len;
	}
		
}
	

int longestIncreasingPath(vector<vector<int> >& matrix)
{
	typedef pair<int, int> co;
	if(matrix.empty() || matrix[0].empty())
		return 0;

	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int> > mem(row, vector<int>(col, -1));
	int max_len = 0;
	for(int r = 0; r < row; ++r)
	{
		for(int c = 0; c < col; ++c)
		{
			int local_max_len = 0;
			findPathLength(matrix, r, c, mem, 1, local_max_len);
			mem[r][c] = local_max_len;
			if(max_len == 0 || max_len < local_max_len)
				max_len = local_max_len;
		}
	}

	

	return max_len;
}

int main()
{
	vector<int> v1;
	for(int i = 0; i < 10; ++i)
		v1.push_back(i);

	vector<int> v2;
	for(int i = 1; i <= 10; ++i)
		v2.push_back(20 - i);

	vector<int> v3;
	for(int i = 0; i < 10; ++i)
		v3.push_back(20 + i);

	vector<int> v4;
	for(int i = 1; i <= 10; ++i)
		v4.push_back(40 - i);

	vector<int> v5;
	for(int i = 0; i < 10; ++i)
		v5.push_back(40 + i);

	vector<int> v6;
	for(int i = 1; i <= 10; ++i)
		v6.push_back(60 - i);

	vector<int> v7;
	for(int i = 0; i < 10; ++i)
		v7.push_back(60 + i);

	vector<int> v8;
	for(int i = 1; i <= 10; ++i)
		v8.push_back(80 - i);

	vector<int> v9;
	for(int i = 0; i < 10; ++i)
		v9.push_back(80 + i);

	vector<int> v10;
	for(int i = 1; i <= 10; ++i)
		v10.push_back(100 - i);

	vector<int> v11;
	for(int i = 0; i < 10; ++i)
		v11.push_back(100 + i);

	vector<int> v12;
	for(int i = 1; i <= 10; ++i)
		v12.push_back(120 - i);

	vector<int> v13;
	for(int i = 1; i <= 10; ++i)
		v13.push_back(140 - i);

	vector<int> v14;
	for(int i = 1; i <= 10; ++i)
		v14.push_back(0);

	vector<vector<int> > matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
	matrix.push_back(v5);
	matrix.push_back(v6);
	matrix.push_back(v7);
	matrix.push_back(v8);
	matrix.push_back(v9);
	matrix.push_back(v10);
	matrix.push_back(v11);
	matrix.push_back(v12);
	matrix.push_back(v13);
	matrix.push_back(v14);

	cout << longestIncreasingPath(matrix) << endl;
	return 1;
}
