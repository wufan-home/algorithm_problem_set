/*
  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
  A region is captured by flipping all 'O's into 'X's in that surrounded region.
  For example,
  X X X X
  X O O X
  X X O X
  X O X X
  After running your function, the board should be:
  X X X X
  X X X X
  X X X X
  X O X X
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void RepalceAux(vector<vector<char> >& board, int x, int y, char rpl)
{
	if(board[x][y] != 'O')
		return;

	queue<pair<int, int> > node_queue;
	board[x][y] = rpl;
	node_queue.push(make_pair(x, y));
	while(!node_queue.empty())
	{
		pair<int, int> cur = node_queue.front();
		node_queue.pop();
		for(int i = -1; i <= 1; i += 2)
		{
			if(cur.first + i >= 0 && cur.first + i < board.size() &&
			   board[cur.first + i][cur.second] == 'O')
			{
				board[cur.first + i][cur.second] = rpl;
				node_queue.push(make_pair(cur.first + i, cur.second));
			}

			if(cur.second + i >= 0 && cur.second + i < board[0].size() &&
			   board[cur.first][cur.second + i] == 'O')
			{
				board[cur.first][cur.second + i] = rpl;
				node_queue.push(make_pair(cur.first, cur.second + i));
			}
		}
	}
}

void solve(vector<vector<char> >& board) {
	if(board.size() <= 2 || board[0].size() <= 2)
		return;

	for(int j = 0; j < board[0].size(); ++j)
	{
		RepalceAux(board, 0, j, 'N');
		RepalceAux(board, board.size() - 1, j, 'N');
	}

	for(int i = 1; i < board.size() - 1; ++i)
	{
		RepalceAux(board, i, 0, 'N');
		RepalceAux(board, i, board[0].size() - 1, 'N');
	}
	
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[0].size(); ++j)
		{
			if(board[i][j] == 'N')
				board[i][j] = 'O';
			else if(board[i][j] == 'O')
				board[i][j] = 'X';
		}
	}
}
