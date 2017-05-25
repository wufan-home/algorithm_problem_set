/*
   A message containing letters from A-Z is being encoded to numbers using the following mapping:

   'A' -> 1
   'B' -> 2
   ...
   'Z' -> 26

   Given an encoded message containing digits, determine the total number of ways to decode it.
   
   For example,
   Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
   
   The number of ways decoding "12" is 2. 
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
            
        cachedCodeNumbers = vector<int>(s.size(), -1);
        getNumOfCodesByIndex(s, 0);
        return cachedCodeNumbers[0];
    }
    
private:
    int getNumOfCodesByIndex(const string& s, int start)
    {
        if(s[start] == '0')
        {
            cachedCodeNumbers[start] = 0;
            return 0;
        }
        
        if(cachedCodeNumbers[start] >= 0)
            return cachedCodeNumbers[start];
        
        cachedCodeNumbers[start] = start == s.size() - 1 ? 1 : getNumOfCodesByIndex(s, start + 1);
        
        if(start < s.size() - 1 && atoi(s.substr(start, 2).c_str()) <= 26)
            cachedCodeNumbers[start] += start == s.size() - 2 ? 1 : getNumOfCodesByIndex(s, start + 2);
            
        return cachedCodeNumbers[start];
    }
    
    vector<int> cachedCodeNumbers;
};
