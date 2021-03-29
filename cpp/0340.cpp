/*
    Given a string, find the length of the longest substring T that contains at most k distinct characters.

    For example, Given s = “eceba” and k = 2,

    T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0)
            return 0;
        
        int maxLen = 0;
        int size = s.size();
        unordered_map<char, int> charWithFreq;
        for(int l = 0, r = 0; r < size;)
        {
            for(; r < size;)
            {
                ++charWithFreq[s[r++]];
                if(charWithFreq.size() > k)
                    break;
                maxLen = max(maxLen, r - l);
            }
            
            if(r < s.size())
            {
                for(; l < size && charWithFreq.size() > k; ++l)
                {
                   if(--charWithFreq[s[l]] == 0)
                        charWithFreq.erase(s[l]);
                }
            }
        }
        
        return maxLen;
    }
};
