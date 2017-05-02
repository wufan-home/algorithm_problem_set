/*
   Implement strStr().
   Returns the index of the first occurrence of needle in haystack, 
   or -1 if needle is not part of haystack. 
   Solution: 1) Brute-force.
   2) KMP or other methods.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;

        int bound = (int) haystack.size() - (int) needle.size() + 1;
        for(int i = 0; i < bound; ++i)
        {
            int j = 0;
            for(; j < needle.size(); ++j)
            {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == needle.size())
                return i;
        }
        
        return -1;
    }
}
