#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
	TrieNode() : m_stop(false), next(26, NULL){}
	
	void FormAWord() { m_stop = true; }
	bool IsAWord() { return m_stop; }
	
	vector<TrieNode *> next;
private:
	bool m_stop;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
	void insert(string word) {
		TrieNode *cur = root;
		for(int i = 0; i < word.size(); ++i)
		{
			if(cur->next[word[i] - 'a'] == NULL)
				cur->next[word[i] - 'a'] = new TrieNode();
			cur = cur->next[word[i] - 'a'];
			if(i == word.size() - 1)
				cur->FormAWord();
		}
	}

    // Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *result = FindANode(word);
		return (result != NULL && result->IsAWord());
	}

    // Returns if there is any word in the trie
    // that starts with the given prefix.
	bool startsWith(string prefix) {
		return FindANode(prefix) != NULL;
	}

private:
	TrieNode *FindANode(const string& prefix)
	{
		TrieNode *cur = root;
		for(int i = 0; i < prefix.size(); ++i)
		{
			if(cur->next[prefix[i] - 'a'] == NULL)
				return NULL;

			cur = cur->next[prefix[i] - 'a'];
		}
		return cur;
	}
	
	TrieNode* root;
};
