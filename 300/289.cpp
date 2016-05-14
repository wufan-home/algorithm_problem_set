#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int live_to_die = 3;
const int die_to_live = 2;

int countLives(int x, int y, vector<vector<int> >& board)
{
	int rv = 0;
	for(int i = -1; i <= 1; ++i)
	{
		for(int j = -1; j <= 1; ++j)
		{
			if((i == 0 && j == 0) ||
			   x + i < 0 || x + i >= board.size() ||
			   y + j < 0 || y + j >= board[0].size())
				continue;

			rv += board[x + i][y + j] - (board[x + i][y + j] < 2 ? 0: 2);
		}
	}
	return rv;
}

void gameOfLife(vector<vector<int> >& board)
{
	map<int, int> change;
	change[live_to_die] = 0;
	change[die_to_live] = 1;
	
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[0].size(); ++j)
		{
			int count = countLives(i, j, board);
			if(board[i][j] == 1 && (count < 2 || count > 3))
				board[i][j] = live_to_die;
			else if(board[i][j] == 0 && count == 3)
				board[i][j] = die_to_live;
		}
	}
	
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[0].size(); ++j)
		{
			if(board[i][j] >= 3)
				board[i][j] = change[board[i][j]];
		}
	}
}

int main()
{
	vector<vector<int> > m(1, vector<int>(2, 1));
	m.push_back(vector<int>(2, 1));
	m[1][1] = 0;
	gameOfLife(m);
	for(int i = 0; i < m.size(); ++i)
	{
		for(int j = 0; j < m[0].size(); ++j)
			cout << m[i][j] << ", ";
		cout << endl;
	}
	return 1;
}
