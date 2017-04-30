/*
	Given a 2D board and a word, find if the word exists in the grid.

	The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

	For example,
	Given board =

	[
	  ['A','B','C','E'],
	  ['S','F','C','S'],
	  ['A','D','E','E']
	]
	word = "ABCCED", -> returns true,
	word = "SEE", -> returns true,
	word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())
            return false;
            
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] != word[0])
                    continue;
                    
                if(checkWordExistenceInBoard(board, word, i, j))
                    return true;
            }
        }
        
        return false;
    }
    
private:
    bool checkWordExistenceInBoard(const vector<vector<char>>& board, const string& word, int row, int col)
    {
        stack<pair<int, int>> stackForChar;
        cached.clear();
        
        string candidate;
        stackForChar.push(make_pair(row, col));
        while(!stackForChar.empty())
        {
            int r = stackForChar.top().first;
            int c = stackForChar.top().second;
            if(cached.find(stackForChar.top()) != cached.end())
            {
                candidate.pop_back();
                cached.erase(stackForChar.top());
                stackForChar.pop();
                continue;
            }
            
            cached.insert(stackForChar.top());
            candidate.push_back(board[r][c]);
            if(candidate == word)
                return true;
            
            if(candidate[candidate.size() - 1] != word[candidate.size() - 1])
                continue;

            for(int i = 0; i < 4; ++i)
            {
                pair<int, int> nextChar = make_pair(r + steps[i][0], c + steps[i][1]);
                if(r + steps[i][0] >= 0 && r + steps[i][0] < board.size() &&
                    c + steps[i][1] >= 0 && c + steps[i][1] < board[0].size() &&
                    cached.find(nextChar) == cached.end())
                        stackForChar.push(nextChar);
            }
        }
        
        return false;
    }

    int steps[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    set<pair<int, int>> cached;
};

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
