/*
    Given a list of strings, you need to find the longest uncommon subsequence among them. 
    The longest uncommon subsequence is defined as the longest subsequence of 
    one of these strings and this subsequence should not be any subsequence of the other strings.

    A subsequence is a sequence that can be derived from one sequence by deleting some characters 
    without changing the order of the remaining elements. Trivially, any string is a subsequence of itself 
    and an empty string is a subsequence of any string.

    The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. 
    If the longest uncommon subsequence doesn't exist, return -1.

    Example 1:
    Input: "aba", "cdc", "eae"
    Output: 3
    Note:

    All the given strings' lengths will not exceed 10.
    The length of the given list will be in the range of [2, 50].
*/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        string res;
        
        for(int i = 0; i < strs.size(); ++i)
        {
            int j = 0;
            for(; j < strs.size(); ++j)
            {
                if(j == i)
                    continue;

                int index = 0;
                for(auto a : strs[j])
                {
                    if(index < strs[i].size() && a == strs[i][index]) ++index;
                }
                if(index == strs[i].size())
                    break;
            }
            
            if(j == strs.size() && strs[i].size() > res.size())
                res = strs[i];
        }
        
        return res.empty() ? -1 : res.size();
    }
};
