/*
	Implement a trie with insert, search, and startsWith methods.
	Note:
	You may assume that all inputs are consist of lowercase letters a-z.
*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curNode = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(curNode->next[word[i] - 'a'] == NULL)
               curNode->next[word[i] - 'a'] = new TrieNode(); 
            
            if(i == word.size() - 1)
                curNode->next[word[i] - 'a']->wordStopsFlag = true;
                
            curNode = curNode->next[word[i] - 'a'];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curNode = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(curNode->next[word[i] - 'a'] == NULL || (i == word.size() - 1 && curNode->next[word[i] - 'a']->wordStopsFlag == false))
                return false;
                
            curNode = curNode->next[word[i] - 'a'];
        }
        
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curNode = root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            if(curNode->next[prefix[i] - 'a'] == NULL)
                return false;
                
            curNode = curNode->next[prefix[i] - 'a'];
        }
        
        return true;
    }
    
private:
    struct TrieNode
    {
        vector<TrieNode *> next;
        bool wordStopsFlag;
        
        TrieNode() : next(26, NULL), wordStopsFlag(false) {}
    };

    TrieNode *root;
};
