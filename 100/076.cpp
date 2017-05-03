/*
	Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

	For example,
	S = "ADOBECODEBANC"
	T = "ABC"

	Minimum window is "BANC".

	Note:
	If there is no such window in S that covers all characters in T, return the empty string "".

	If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
*/

class Solution {
public:
    string minWindow(string s, string t) {
        const int ss = s.size();
        const int ts = t.size();
        
        if(ts == 0  || ss < ts)
            return "";
            
        vector<int> frequency(256, 0);
        vector<int> count(256, 0);
        for(int i = 0; i < t.size(); ++i)
            ++frequency[t[i]];
        
        int minWindowLength = INT_MAX;
        int finalStart = 0;
        for(int start = 0, end = 0; end < s.size(); ++end)
        {
            if(frequency[s[end]] == 0)
                continue;
              
            ++count[s[end]];
            if(!isCountLargerOrEqualToFrequency(count, frequency))
                continue;
            
            for(; isCountLargerOrEqualToFrequency(count, frequency); ++start)
            {
                if(frequency[s[start]])
                    --count[s[start]];
            }
            ++count[s[--start]];
            
            if(end - start + 1 < minWindowLength)
            {
                minWindowLength = end - start + 1;
                finalStart = start;
            }
            
            --count[s[start++]];
        }
        
        return minWindowLength == INT_MAX ? "" : s.substr(finalStart, minWindowLength);
    }
    
private:
    bool isCountLargerOrEqualToFrequency(const vector<int>& count, const vector<int>& frequency)
    {
        int size = frequency.size();
        for(int i = 0; i < size; ++i)
        {
            if(count[i] < frequency[i])
                return false;
        }
        return true;
    }
};
