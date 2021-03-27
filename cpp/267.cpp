/*
    Given a string s, return all the palindromic permutations (without duplicates) of it. 
    Return an empty list if no palindromic permutation could be form.

    For example:

    Given s = "aabb", return ["abba", "baab"].

    Given s = "abc", return [].
*/

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int count[256] = {0};
        for(int i = 0; i < s.size(); ++i)
            ++count[s[i]];
        
        int oddDigit = -1;
        for(int i = 0; i < 256; ++i)
        {
            if(count[i] % 2 == 1)
            {
                if(oddDigit > -1)
                    return vector<string>();
                
                oddDigit = i;
            }
        }
        
        string candidate;
        for(int i = 0; i < 256; ++i)
        {
            if(count[i] > 0)
                candidate.append(count[i] / 2, char(i));
        }

        vector<string> res;
        getPermutation(candidate, 0, oddDigit, res);
        return res;
    }
    
private:
    void getPermutation(string& candidate, int i, int odd, vector<string>& res)
    {
        if(candidate.empty() || i == candidate.size() - 1)
        {
            res.push_back(candidate);
            if(odd > -1)
                res.back().push_back(char(odd));
            
            for(int i = res.back().size() - (odd > -1 ? 2 : 1); i >= 0; --i)
                res.back().push_back(res.back()[i]);
            
            return;
        }
        
        for(int j = i; j < candidate.size();)
        {
            swap(candidate[i], candidate[j]);
            getPermutation(candidate, i + 1, odd, res);
            for(++j; j < candidate.size() && candidate[j] == candidate[i]; ++j) {}
        }
        
        sort(candidate.begin() + i, candidate.end());
    }
};
