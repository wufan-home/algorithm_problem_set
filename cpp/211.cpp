/*
	Design a data structure that supports the following two operations:

	void addWord(word)
	bool search(word)
	search(word) can search a literal word or a regular expression string containing only letters a-z or .. 
	A . means it can represent any one letter.

	For example:

	addWord("bad")
	addWord("dad")
	addWord("mad")
	search("pad") -> false
	search("bad") -> true
	search(".ad") -> true
	search("b..") -> true
	Note:
	You may assume that all words are consist of lowercase letters a-z.
*/

class TrieNode
{
public:
    TrieNode()
    {
        next = vector<TrieNode *>(26, NULL);
        tail = false;
    }

    ~TrieNode()
    {
        for(int i = 0; i < 26; ++i)
            delete next[i];
    }

    vector<TrieNode *> next;
    bool tail;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int len = word.size();
        TrieNode *cur = root;
        for(int i = 0; i < len; ++i)
        {
            if(cur->next[word[i] - 'a'] == NULL)
                cur->next[word[i] - 'a'] = new TrieNode();
            
            if(i == len - 1)
                cur->next[word[i] - 'a']->tail = true;
            
            cur = cur->next[word[i] - 'a'];
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchAux(word, 0, root);
    }
    
private:
    bool searchAux(const string& word, int start, TrieNode *root)
    {
        bool res = false;
        if(start == word.size())
            return root->tail;
        else if(word[start] == '.')
        {
            for(int i = 0; i < 26; ++i)
            {
                if(root->next[i] && searchAux(word, start + 1, root->next[i]))
                {
                    res = true;
                    break;
                }
            }
        }
        else
        {
            res = (root->next[word[start] - 'a'] != NULL && 
                searchAux(word, start + 1, root->next[word[start] - 'a'])); 
        }
        
        return res;
    }
    
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
