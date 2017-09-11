/*
    There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
    You receive a list of non-empty words from the dictionary, 
    where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

    Example 1:
    Given the following words in dictionary,

    [
      "wrt",
      "wrf",
      "er",
      "ett",
      "rftt"
    ]
    The correct order is: "wertf".

    Example 2:
    Given the following words in dictionary,

    [
      "z",
      "x"
    ]
    The correct order is: "zx".

    Example 3:
    Given the following words in dictionary,

    [
      "z",
      "x",
      "z"
    ]
    The order is invalid, so return "".

    Note:
    You may assume all letters are in lowercase.
    You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
    If the order is invalid, return an empty string.
    There may be multiple valid order of letters, return any one of them is fine.
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        
        int maxLen = -1;
        for(int i = 0; i < words.size(); ++i)
            maxLen = max(maxLen, (int)words[i].size());
        
        unordered_map<char, unordered_set<char>> adj;
        int size = words.size();
        unordered_set<char> finished;
        for(int i = 0; i < maxLen; ++i)
        {
            int len = finished.size();
            unordered_set<char> visited;
            vector<char> cur;
            for(int j = 0; j < size; ++j)
            {
                if(i < words[j].size() && adj.find(words[j][i]) == adj.end())
                {
                    adj[words[j][i]] = unordered_set<char>();
                }
                cur.push_back(i == words[j].size() ? '\0' : words[j][i]);
            }
            
            for(int j = 0; j < (int)cur.size() - 1; ++j)
            {
                for(int k = j + 1; k < (int)cur.size(); ++k)
                {
                    if(cur[j] == cur[k] || cur[j] == '\0' || cur[k] == '\0')
                        continue;
                    
                    if(i > 0 && words[j].substr(0, i) != words[k].substr(0, i))
                        continue;

                    visited.insert(cur[j]);
                    visited.insert(cur[k]);
                    adj[cur[j]].insert(cur[k]);
                }
            }
            
            finished.insert(visited.begin(), visited.end());
        }
        
        int total = adj.size();
        
        while(res.size() < total)
        {
            int len = res.size();
            
            for(unordered_map<char, unordered_set<char>>::iterator it = adj.begin(); it != adj.end(); ++it)
            {
                if(it->second.empty() && find(res.begin(), res.end(), it->first) == res.end())
                    res.push_back(it->first);
            }
            
            if(len == res.size() && res.size() < total)
                return "";
            
            for(int i = 0; i < res.size(); ++i)
            {
                for(unordered_map<char, unordered_set<char>>::iterator it = adj.begin(); it != adj.end(); ++it)
                    it->second.erase(res[i]);
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
