/*
    Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
    so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

    Example 1:
    Given words = ["bat", "tab", "cat"]
    Return [[0, 1], [1, 0]]
    The palindromes are ["battab", "tabbat"]
    Example 2:
    Given words = ["abcd", "dcba", "lls", "s", "sssll"]
    Return [[0, 1], [1, 0], [3, 2], [2, 4]]
    The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
    Credits:
    Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> pairs;
        
        int size = words.size();
        unordered_map<string, int> m;
        set<int> s;
        for(int i = 0; i < size; ++i)
        {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        
        for(int i = 0; i < size; ++i)
        {
            reverse(words[i].begin(), words[i].end());
            if(m.find(words[i]) != m.end() && m[words[i]] != i)
                pairs.push_back(vector<int>({i, m[words[i]]}));
            
            int wordSize = words[i].size();
            set<int>::iterator end = s.find(wordSize);
            for(set<int>::iterator it = s.begin(); it != end; ++it)
            {
                int len = *it;
                
                //left
                if(m.find(words[i].substr(0, len)) != m.end() && isPalindrome(words[i], len, words[i].size() - 1))
                    pairs.push_back(vector<int>({m[words[i].substr(0, len)], i}));
                
                //right
                if(m.find(words[i].substr(words[i].size() - len)) != m.end() && isPalindrome(words[i], 0, words[i].size() - len -1))
                    pairs.push_back(vector<int>({i, m[words[i].substr(words[i].size() - len)]}));
            }
        }
        
        return pairs;
    }
    
private:
    bool isPalindrome(const string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        
        return true;
    }
};
