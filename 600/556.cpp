/*
    Given a positive 32-bit integer n, you need to find the smallest 32-bit integer 
    which has exactly the same digits existing in the integer n and is greater in value than n. 
    If no such positive 32-bit integer exists, you need to return -1.

    Example 1:
    Input: 12
    Output: 21
    Example 2:
    Input: 21
    Output: -1
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        int size = s.size();
        int l = size - 2;
        char value = '\0';
        int index = size;
        for(; l >= 0; --l)
        {
            if(s[l] < s[l + 1])
            {
                for(int i = size - 1; i > l; --i)
                {
                    if(s[i] <= s[l])
                        continue;
                    
                    if(value == '\0' || s[i] < value)
                    {
                        value = s[i];
                        index = i;
                    }
                }
                
                break;
            }
        }
        
        if(l >= 0 && index < size)
        {
            swap(s[l], s[index]);
            sort(s.begin() + l + 1, s.end());
        }
        
        int newValue = atoi(s.c_str());
        
        return newValue > n ? newValue : -1;
    }
};
