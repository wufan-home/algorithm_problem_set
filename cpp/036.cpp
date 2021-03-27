/*
  Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
  The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
  A partially filled sudoku which is valid.
  Note:
  A valid Sudoku board (partially filled) is not necessarily solvable. 
  Only the filled cells need to be validated.
*/

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
				return false;

			row_test[i][p] = true;
			col_test[j][p] = true;
			block_test[3 * (i / 3) + j / 3][p] = true;
		}
	}

	return true;
}
