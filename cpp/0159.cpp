/*
    Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
    For example, Given s = “eceba”,
    T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())
            return 0;
        
        int maxLength = 1;
        int start = 0;
        vector<pair<char, int>> charToIndex({make_pair(s[0], 0), make_pair('\0', -1)});
        for(int i = 1; i < s.size(); ++i)
        {
            pair<char, int>& first = charToIndex[0];
            pair<char, int>& second = charToIndex[1];
            
            if(s[i] == first.first)
            {
                if(first.second < second.second)
                    first.second = i;
            }
            else if(s[i] == second.first)
            {
                if(second.second < first.second)
                    second.second = i;
            }
            else if(second.first == '\0')
            {
                second.first = s[i];
                second.second = i;
            }
            else 
            {
                if(first.second > second.second)
                {
                    second.first = s[i];
                    second.second = i;
                    start = first.second;
                }
                else
                {
                    first.first = s[i];
                    first.second = i;
                    start = second.second;
                }
            }
            
            maxLength = max(maxLength, i - start + 1);
        }
        
        return maxLength;
        
    }
};
