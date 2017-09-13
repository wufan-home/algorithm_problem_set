/*
	Implement a trie with insert, search, and startsWith methods.
	Note:
	You may assume that all inputs are consist of lowercase letters a-z.
*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        tailFlag = false;
        next = vector<Trie *>(26, NULL);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.empty())
            return ;
        
        Trie *cur = this;
        for(int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if((*cur).next[index] == NULL)
                (*cur).next[index] = new Trie();
            
            cur = (*cur).next[index];
            if(i == word.size() - 1)
                cur->tailFlag = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *endNode = traverseToEnd(word);
        return endNode != NULL && endNode->tailFlag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return traverseToEnd(prefix) != NULL;
    }
private:
    Trie *traverseToEnd(const string &word)
    {
        if(word.empty())
            return NULL;
        
        Trie *cur = this;
        for(int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            cur = (*cur).next[index];
            if(cur == NULL)
                break;
        }
        
        return cur;
    }
    
    bool tailFlag;
    vector<Trie *> next;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
