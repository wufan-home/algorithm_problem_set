#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
	TrieNode() : next(26, NULL), m_stop(false) {}
	~TrieNode() {}

	friend class Trie;
private:
	vector<TrieNode*> next;
	bool m_stop;
};

class Trie
{
public:
	Trie() { root = new TrieNode(); }
	~Trie() {}

	void Add(const string& word);
	bool Search(const string& word);
private:
	TrieNode* SearchRecursively(const string& word, int start, TrieNode *head);
	TrieNode *root;
};

void Trie::Add(const string& word)
{
	TrieNode *cur = root;
	for(int i = 0; i < word.size(); ++i)
	{
		if(!cur->next[word[i] - 'a'])
			cur->next[word[i] - 'a'] = new TrieNode;

		cur = cur->next[word[i] - 'a'];
	}
	cur->m_stop = true;
}

bool Trie::Search(const string& word)
{
	TrieNode *cur = SearchRecursively(word, 0, root);
	return (cur && cur->m_stop);
}

TrieNode* Trie::SearchRecursively(const string& word, int start, TrieNode *head)
{
	int s = 0;
	int e = 25;
	if(word[start] != '.')
		s = e = word[start] - 'a';

	TrieNode *result = NULL;
	for(int i = s; i <= e; ++i)
	{
		TrieNode *cur = head->next[i];
		if(cur && (result = SearchRecursively(word, start + 1, cur)))
			break;
	}
	return result;
}

class WordDictionary {
public:
	WordDictionary() {
		m_root = new Trie;
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		m_root->Add(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return m_root->Search(word);
	}

private:
	Trie *m_root;
};

int main()
{
	WordDictionary wd;
	cout << (wd.search("a") ? "True" : "False") << endl;
	wd.addWord("a");
	cout << (wd.search("a") ? "True" : "False") << endl;
	return 0;
}

