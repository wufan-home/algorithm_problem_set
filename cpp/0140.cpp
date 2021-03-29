/*
    Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
    add spaces in s to construct a sentence where each word is a valid dictionary word. 
    You may assume the dictionary does not contain duplicate words.

    Return all such possible sentences.

    For example, given
    s = "catsanddog",
    dict = ["cat", "cats", "and", "sand", "dog"].

    A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> breaks;
        if(s.empty() || wordDict.empty())
            return breaks;
            
        for(int i = 0; i < wordDict.size(); ++i)
            hashDict.insert(wordDict[i]);
            
        possible = vector<bool>(s.size(), true);
            
        string curWord;
        getBreaks(s, 0, curWord, breaks);
        return breaks;
    }
    
private:
    
    void getBreaks(const string& s, int start, string& curWord, vector<string>& breaks)
    {
        if(start == s.size())
        {
            breaks.push_back(curWord);
            return;
        }
        
        int validWordBreaks = breaks.size();
        int length = curWord.size();
        for(int i = start; i < s.size(); ++i)
        {
            int len = i - start + 1;
            string nextWord = s.substr(start, len);
            if(hashDict.find(nextWord) != hashDict.end() && possible[start])
            {
                curWord.append(length == 0 ? "" : " ");
                curWord.append(nextWord);
                getBreaks(s, i + 1, curWord, breaks);
                curWord.resize(length);
            }
        }
        
        possible[start] = (breaks.size() != validWordBreaks);
    }
    
    unordered_set<string> hashDict;
    vector<bool> possible;
};
