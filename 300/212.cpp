/*
  Given a 2D board and a list of words from the dictionary, find all words in the board.
  Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or 
  vertically neighboring. The same letter cell may not be used more than once in a word.
  For example,
  Given words = ["oath","pea","eat","rain"] and board =
  [
    ['o','a','a','n'],
    ['e','t','a','e'],
    ['i','h','k','r'],
    ['i','f','l','v']
  ]
  Return ["eat","oath"].
  Note:
  You may assume that all inputs are consist of lowercase letters a-z.
  click to show hint.
  You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
  If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. 
  What kind of data structure could answer such query efficiently? Does a hash table work? 
  Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, 
  please work on this problem: Implement Trie (Prefix Tree) first.
*/

class Solution {
private:
	struct node
	{
		node() : m_end(false)
		{
			memset(m_next, NULL, 26 * sizeof(node*));
		}
		node *m_next[26];
		bool m_end;
	};

	node *m_head;
	int offset[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
public:
	void AddToTrie(node *head, const string& word)
	{
		if (head == NULL)
			return;

		node *cur = head;
		for (int i = 0; i < word.size(); ++i)
		{
			if(cur->m_next[word[i] - 'a'] == NULL)
				cur->m_next[word[i] - 'a'] = new node;

				cur = cur->m_next[word[i] - 'a'];
		}
		cur->m_end = true;
	}

	void Search(vector<vector<char>>& board, int i, int j,
				node *head, string& word,
				unordered_set<string>& found,
				vector<vector<bool>>& visited)
	{
		if (head->m_next[board[i][j] - 'a'] == NULL)
			return;
		else
		{
			word.push_back(board[i][j]);
			if (head->m_next[board[i][j] - 'a']->m_end)
				found.insert(word);

			visited[i][j] = true;
			for (int k = 0; k < 4; ++k)
			{
				int x = i + offset[k][0];
				int y = j + offset[k][1];
				if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visited[x][y])
					Search(board, x, y, head->m_next[board[i][j] - 'a'], word, found, visited);
			}
			
			visited[i][j] = false;
			word.pop_back();
		}
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		if (words.empty())
			return result;

		m_head = new node();
		for (int i = 0; i < words.size(); ++i)
			AddToTrie(m_head, words[i]);

		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		unordered_set<string> found;
		string word;
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				word.clear();
				Search(board, i, j, m_head, word, found, visited);
			}
		}

		for (unordered_set<string>::iterator it = found.begin(); it != found.end(); ++it)
			result.push_back(*it);

		return result;
	}
};
