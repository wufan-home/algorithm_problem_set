/*
    Implement a magic directory with buildDict, and search methods.

    For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

    For the method search, you'll be given a word, and judge whether if you modify exactly one character 
    into another character in this word, the modified word is in the dictionary you just built.

    Example 1:
    Input: buildDict(["hello", "leetcode"]), Output: Null
    Input: search("hello"), Output: False
    Input: search("hhllo"), Output: True
    Input: search("hell"), Output: False
    Input: search("leetcoded"), Output: False
    Note:
    You may assume that all the inputs are consist of lowercase letters a-z.
    For contest purpose, the test data is rather small by now. 
    You could think about highly efficient algorithm after the contest.
    Please remember to RESET your class variables declared in class MagicDictionary, 
    as static/class variables are persisted across multiple test cases. Please see here for more details.
*/

1 -
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto str : dict)
        {
            int len = str.size();
            if(_dict.find(len) == _dict.end())
                _dict[len] = unordered_set<string>();
            
            _dict[len].insert(str);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.size();
        unordered_set<string> &cur = _dict[len];
        for(auto str : cur)
        {
            int count = 0;
            for(int i = 0; i < len; ++i)
            {
                if((count += (word[i] != str[i])) > 1)
                    break;
            }
            
            if(count == 1)
                return true;
        }
        
        return false;
    }
    
private:
    unordered_map<int, unordered_set<string>> _dict;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
 
 2 - 
 class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto str : dict)
            _dict.insert(str);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.size();
        for(int i = 0; i < len; ++i)
        {
            char t = word[i];
            for(char c = 'a'; c <= 'z'; ++c)
            {
                if(c == t)
                    continue;
                
                word[i] = c;
                if(_dict.find(word) != _dict.end())
                    return true;
            }
            
            word[i] = t;
        }
        
        return false;
    }
    
private:
    unordered_set<string> _dict;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
