// 51.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CheckAvail(const vector<string>& board, pair<int, int> position)
{
	int n = board.size();
	int row = position.first;
	int col = position.second;
	for (int i = 0; i < row; ++i)
	{
		if (board[i][col] == board[row][col])
			return false;
	}

	for (int i = 1; i <= col; ++i)
	{
		if (row - i >= 0 && board[row - i][col - i] == board[row][col])
			return false;

		if (row + i < n && board[row + i][col - i] == board[row][col])
			return false;
	}

	for (int i = 1; i <= n - col; ++i)
	{
		if (row - i >= 0 && board[row - i][col + i] == board[row][col])
			return false;

		if (row + i < n && board[row + i][col + i] == board[row][col])
			return false;
	}

	return true;
}

void GetSolutions(vector<string>& board, int row, int n, vector<vector<string> >& results)
{
	for (int i = 0; i < n; ++i)
	{
		board[row][i] = 'Q';
		if (row == n - 1)
		{
			if (CheckAvail(board, make_pair(row, i)))
				results.push_back(board);
		}
		else
		{
			if (CheckAvail(board, make_pair(row, i)))
				GetSolutions(board, row + 1, n, results);
		}
		board[row][i] = '.';
	}
}

vector<vector<string>> solveNQueens(int n)
{
	vector<vector<string> > results;
	if (n <= 0)
		return results;

	if (n == 1)
	{
		string result("Q");
		results.push_back(vector<string>(1, result));
		return results;
	}

	vector<string> board(n, string(n, '.'));
	GetSolutions(board, 0, n, results);

	return results;
}

int main()
{
	vector<vector<string> > r = solveNQueens(8);
	for (int i = 0; i < r.size(); ++i)
	{
		for (int j = 0; j < r[i].size(); ++j)
			cout << r[i][j] << endl;

		cout << endl;
	}
	cout << endl;
    return 0;
}

