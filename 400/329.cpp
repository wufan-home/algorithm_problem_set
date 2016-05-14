#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search_dfs_aux(const vector<vector<int> >& matrix,
    		   int x, int y,
    		   vector<vector<int> >& aux)
    {
    	int max_len = 1;
    	int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    	for(int i = 0; i < 4; ++i)
    	{
    		int next_x = x + offset[i][0];
    		int next_y = y + offset[i][1];
    		if(next_x < matrix.size() && next_x >= 0 &&
    		   next_y < matrix[0].size() && next_y >= 0 &&
    		   matrix[x][y] < matrix[next_x][next_y])
    		{
    			max_len = max(max_len,
    				      1 + (aux[next_x][next_y] ?
    					   aux[next_x][next_y] :
    					   search_dfs_aux(matrix, next_x, next_y, aux)));
    		}
    	}
    	aux[x][y] = max_len;
    	return max_len;
    }
    
    int longestIncreasingPath(vector<vector<int> >& matrix)
    {
    	if(matrix.empty() || matrix[0].empty())
    		return 0;
    
    	int row = matrix.size();
    	int col = matrix[0].size();
    	vector<vector<int> > aux(row, vector<int>(col, 0));
    	int max_len = 1;
    	for(int i = 0; i < row; ++i)
    	{
    		for(int j = 0; j < col; ++j)
    			max_len = max(max_len, search_dfs_aux(matrix, i, j, aux));
    	}
    
    	return max_len;
    }

int main()
{
	vector<vector<int> > m({{9,9,4},{6,6,8},{2,1,1}});
	cout << longestIncreasingPath(m) << endl;
	return 1;
}
