/*
    Given a string s, partition s such that every substring of the partition is a palindrome.
    Return all possible palindrome partitioning of s.
    For example, given s = "aab",
    Return
    [
      ["aa","b"],
      ["a","a","b"]
    ]
*/

class Solution {
public:
    bool IsPalindrome(const string& str) {
        for(int begin = 0, end = str.size() - 1; begin < end; ++begin, --end)
            if(str[begin] != str[end])
                return false;
        return true;
    }
    
    void PopulatePalindromes(string str, vector<string>& partition, vector<vector<string> >& candidates)
    {
        for(int i = 1; i <= str.size(); ++i) {
            string prefix = str.substr(0, i);
            if(IsPalindrome(prefix)) {
                partition.push_back(prefix);
                if(i == str.size())
                    candidates.push_back(partition);
                else
                    PopulatePalindromes(str.substr(i), partition, candidates);

                partition.erase(partition.end() - 1, partition.end());
            }
        }
    }
    
    vector<vector<string> > partition(string s) {
        vector<vector<string> > candidates;
        vector<string> partition;
        PopulatePalindromes(s, partition, candidates);
        return candidates;
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty())
            return vector<vector<string>>();

        vector<vector<vector<string>>> cache(s.size(), vector<vector<string>>());
        for(int r = 0; r < s.size(); ++r)
        {
            vector<vector<string>> currentPalindromes;
            for(int l = r; l >= 0; --l)
            {
                if(l != r && !checkPalindrome(s, l, r))
                    continue;
                    
                string suffix = s.substr(l, r - l + 1);
                if(l == 0)
                    currentPalindromes.push_back(vector<string>(1, suffix));
                else
                {
                    for(int i = 0; i < cache[l - 1].size(); ++i)
                    {
                        currentPalindromes.push_back(cache[l - 1][i]);
                        currentPalindromes[currentPalindromes.size() - 1].push_back(suffix);
                    }
                }
            }
            cache[r] = currentPalindromes;
        }
        
        return cache[s.size() - 1];
    }
    
private:
    bool checkPalindrome(const string& s, int l, int r)
    {
        for(; l < r; ++l, --r)
        {
            if(s[l] != s[r])
                return false;
        }
        
        return true;
    }
    
    
};
