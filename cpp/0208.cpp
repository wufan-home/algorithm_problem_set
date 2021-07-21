class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->next[c - 'a'] == NULL) {
                cur->next[c - 'a'] = new TrieNode();
            }
            
            cur = cur->next[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->next[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->next[c - 'a'];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (cur->next[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->next[c - 'a'];
        }
        return true;
    }
    
private:
    struct TrieNode {
        bool isEnd;
        vector<TrieNode*> next;
        TrieNode() : isEnd(false), next(vector<TrieNode*>(26, NULL)) {}
    };
    
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
