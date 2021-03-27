/*
    Given a string, sort it in decreasing order based on the frequency of characters.

    Example 1:

    Input:
    "tree"

    Output:
    "eert"

    Explanation:
    'e' appears twice while 'r' and 't' both appear once.
    So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
    Example 2:

    Input:
    "cccaaa"

    Output:
    "cccaaa"

    Explanation:
    Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
    Note that "cacaca" is incorrect, as the same characters must be together.
    Example 3:

    Input:
    "Aabb"

    Output:
    "bbAa"

    Explanation:
    "bbaA" is also a valid answer, but "Aabb" is incorrect.
    Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> count(256, make_pair(0, 0));
        for(int i = 0; i < 256; ++i)
            count[i].first = i;
        
        for(int i = 0; i < s.size(); ++i)
            ++count[s[i]].second;
        
        sort(count.begin(), count.end(), compare);
        string res(s);
        int index = 0;
        for(int i = 255; i >= 0 && count[i].second > 0; --i)
        {
            for(int j = 0; j < count[i].second; ++j)
                res[index++] = char(count[i].first);
        }
        
        return res;
    }
    
private:
    static bool compare(const pair<int, int>& l, const pair<int, int>& r)
    {
        return l.second < r.second || (l.second == r.second && l.first < r.first);
    }
};
