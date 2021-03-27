/*
    Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

    Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

    The order of output does not matter.

    Example 1:

    Input:
    s: "cbaebabacd" p: "abc"

    Output:
    [0, 6]

    Explanation:
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    The substring with start index = 6 is "bac", which is an anagram of "abc".
    Example 2:

    Input:
    s: "abab" p: "ab"

    Output:
    [0, 1, 2]

    Explanation:
    The substring with start index = 0 is "ab", which is an anagram of "ab".
    The substring with start index = 1 is "ba", which is an anagram of "ab".
    The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> starts;
        if(s.empty() || p.empty() || s.size() < p.size())
            return starts;
           
        vector<int> count(26, 0);
        vector<int> localCount(26, 0);
        for(int i = 0; i < p.size(); ++i)
        {
            ++count[p[i] - 'a'];
            ++localCount[s[i] - 'a'];
        }
        
        if(localCount == count)
            starts.push_back(0);

        for(int start = 1, end = p.size(); end < s.size(); ++start, ++end)
        {
            --localCount[s[start - 1] - 'a'];
            ++localCount[s[end] - 'a'];
            if(localCount == count)
                starts.push_back(start);
        }
        
        return starts;
    }
};
