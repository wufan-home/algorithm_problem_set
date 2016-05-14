#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool SearchAux(vector<vector<char> >& board, int x, int y,
	       const string& word, int cur)
{
        int size = word.size();
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i = -1; i <= 1; ++i) {
		for(int j = -1; j <= 1; ++j) {
			if((i == 0 && j !=0) || (i != 0 && j == 0)) {
				if(x + i < 0 || x + i >= rows
				   || y + j < 0 || y +j >= cols 
				   || board[x + i][y + j] != word[cur])
					continue;

				cout << "[" << x << ", " << y << "] " << cur << endl;
				if(x == board.size() - 1 && y == board.size() - 1)
					cout << "haha = " << search_index << endl;
				
				if(cur == word.size())
					return true;
				board[x + i][y + j] = '#';
				if(SearchAux(board, x + i, y + j, word, cur + 1))
					return true;
				board[x + i][y + j] = word[cur];
			}
		}
        }       
        return false;
}

bool exist(vector<vector<char> >& board, string word) {
        if(board.empty() || word.empty())
		return false;
            
        vector<pair<int, int> > starts;
        for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[0].size(); ++j) {
			if(board[i][j] == word[0])
			{
				board[i][j] = '#';
				if(SearchAux(board, i, j, word, 1))
					return true;
				board[i][j] = word[0];
			}
		}
        }
        
        if(word.size() == 1 && starts.size() > 0)
		return true;
        
        return false;
    }

int main()
{
	int N = 0;
	cin >> N;
	vector<char> row(N, 'a');
	vector<vector<char> > board;
	for(int i = 0; i < N; ++i)
		board.push_back(row);
	board[N - 1][N - 1] = 'b';
	string s(N * N, 'a');
	s[N * N - 1] = 'b';
	cout << exist(board, s) << endl;
	return 1;
}
