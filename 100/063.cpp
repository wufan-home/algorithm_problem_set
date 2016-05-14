#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
	int col = obstacleGrid[0].size();
	if(row == 0 || col == 0)
		return 0;

	vector<vector<int> > board(row, vector<int>(col, 0));
	board[0][0] = (!obstacleGrid[0][0] ? 1 : 0);
	for(int i = 1; i < col; ++i)
	{
		if(!obstacleGrid[0][i])
			board[0][i] = board[0][i - 1];
	}

	for(int i = 1; i < row; ++i)
	{
		if(!obstacleGrid[i][0])
			board[i - 1][0] = board[i][0];
	}

	for(int i = 1; i < row; ++i)
	{
		for(int j = 1; j < col; ++j)
		{
			if(obstacleGrid[i][j])
				continue;
			
			board[i][j] = board[i - 1][j] + board[i][j - 1];
		}
	}

	return board[row - 1][col - 1];
}

int main()
{
	return 1;
}
