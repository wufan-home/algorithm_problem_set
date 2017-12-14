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
