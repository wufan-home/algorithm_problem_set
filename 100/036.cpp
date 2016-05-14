#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool isValidSudoku(vector<vector<char> >& board) {
        if(board.size() != 9 || board[0].size() != 9)
		return false;

	vector<vector<bool> > row_test(10, vector<bool>(10, false));
	vector<vector<bool> > col_test(10, vector<bool>(10, false));
	vector<vector<bool> > block_test(10, vector<bool>(10, false));
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			if(board[i][j] == '.')
				continue;

			int p = board[i][j] - '0';
			if(row_test[i][p] || col_test[j][p] || block_test[3 * (i / 3) + j / 3][p])
			{
				cout << i << ", " << j << endl;
				cout << board[i][j] << endl;
				cout << row_test[i][p] << endl;
				cout << col_test[j][p] << endl;
				cout << block_test[3 * (i / 3) + j / 3][p] << endl;
				return false;
			}

			row_test[i][p] = true;
			col_test[j][p] = true;
			block_test[3 * (i / 3) + j / 3][p] = true;
		}
	}

	return true;
}

int main()
{
//	["..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."]
	vector<vector<char> > board;
	for(int i = 0; i < 9; ++i)
	{
		board.push_back(vector<char>());
		for(int j = 0; j < 9; ++j)
			board[i].push_back('.');
	}

	board[0][2] = '5';
	board[0][8] = '6';
	board[1][4] = '1';
	board[1][5] = '4';
	board[3][5] = '9';
	board[3][6] = '2';
	board[4][0] = '5';
	board[4][5] = '2';
	board[5][7] = '3';
	board[6][3] = '5';
	board[6][4] = '4';
	board[7][0] = '3';
	board[7][6] = '4';
	board[7][7] = '2';
	board[8][3] = '2';
	board[8][4] = '7';
	board[8][6] = '6';
	cout << isValidSudoku(board) << endl;
	
	return 1;
}
