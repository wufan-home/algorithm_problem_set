/*
    Given a set of words (without duplicates), find all word squares you can build from them.

    A sequence of words forms a valid word square if the kth row and column read the exact same string, 
    where 0 ≤ k < max(numRows, numColumns).

    For example, the word sequence ["ball","area","lead","lady"] forms a word square 
    because each word reads the same both horizontally and vertically.

    b a l l
    a r e a
    l e a d
    l a d y
    Note:
    There are at least 1 and at most 1000 words.
    All words will have the exact same length.
    Word length is at least 1 and at most 5.
    Each word contains only lowercase English alphabet a-z.
    Example 1:

    Input:
    ["area","lead","wall","lady","ball"]

    Output:
    [
      [ "wall",
        "area",
        "lead",
        "lady"
      ],
      [ "ball",
        "area",
        "lead",
        "lady"
      ]
    ]

    Explanation:
    The output consists of two word squares. The order of output does not matter 
    (just the order of words in each word square matters).
    Example 2:

    Input:
    ["abat","baba","atan","atal"]

    Output:
    [
      [ "baba",
        "abat",
        "baba",
        "atan"
      ],
      [ "baba",
        "abat",
        "baba",
        "atal"
      ]
    ]

    Explanation:
    The output consists of two word squares. The order of output does not matter 
    (just the order of words in each word square matters).
*/

struct TrieNode
{
    bool isTail;
    vector<TrieNode *> next;
    
    TrieNode() : next(vector<TrieNode *>(26, NULL)), isTail(false) {}
};

class Solution {
public:
    Solution() : root(new TrieNode()) {}
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res = vector<vector<string>>();
        if(words.empty())
            return res;
        
        for(int i = 0; i < words.size(); ++i)
            addWord(words[i]);
        
        int len = words[0].size();
        unordered_set<string> used;
        vector<string> square;
        for(int i = 0; i < words.size(); ++i)
        {
            if(used.find(words[i]) != used.end())
                continue;
            
            //cout << words[i] << ": " << endl;
            square.push_back(words[i]);
            used.insert(words[i]);
            createSquare(1, len, square, res);
            square.pop_back();
        }
        
        return res;
    }
    
private:
    void createSquare(int start, 
                      const int len, 
                      vector<string> &square,
                      vector<vector<string>> &res)
    {
        if(start == len)
        {
            res.push_back(square);
            return;
        }
        
        string prefix(len, '.');
        for(int i = 0; i < start; ++i)
            prefix[i] = square[i][start];
        
        //cout << "prefix = " << prefix << endl;
        
        string curWord;
        vector<string> wordList; 
        searchWords(prefix, 0, root, curWord, wordList);
        for(int i = 0; i < wordList.size(); ++i)
        {
            square.push_back(wordList[i]);
            createSquare(start + 1, len, square, res);
            square.pop_back();
        }
    }
    
    void searchWords(const string &prefix, int start, TrieNode *cur, string &curWord, vector<string> &wordList)
    {
        if(cur == NULL)
            return;
        
        if(start == prefix.size())
        {
            wordList.push_back(curWord);
            return;
        }
        
        if(prefix[start] == '.')
        {
            for(int i = 0; i < 26; ++i)
            {
                //cout << i << "->" << (cur->next[i] == NULL ? "null" : "not") << endl;
                if(cur->next[i] == NULL)
                    continue;
                
                curWord.push_back(i + 'a');
                searchWords(prefix, start + 1, cur->next[i], curWord, wordList);
                curWord.pop_back();
            }
        }
        else
        {
            curWord.push_back(prefix[start]);
            //cout << prefix[start] << "->" << (cur->next[prefix[start] - 'a'] == NULL ? "null" : "not") << endl;
            searchWords(prefix, start + 1, cur->next[prefix[start] - 'a'], curWord, wordList);
            curWord.pop_back();
        }
    }
    
    
    
    void addWord(const string &word)
    {
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(cur->next[word[i] - 'a'] == NULL)
                cur->next[word[i] - 'a'] = new TrieNode();
            
            if(i == word.size() - 1)
                cur->next[word[i] - 'a']->isTail = true;

            cur = cur->next[word[i] - 'a'];
        }
    }
    
    TrieNode *root;
};
