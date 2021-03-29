/*
    Given an integer, return its base 7 string representation.

    Example 1:
    Input: 100
    Output: "202"
    Example 2:
    Input: -7
    Output: "-10"
    Note: The input will be in range of [-1e7, 1e7].
*/

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
            
        string expansion;
        if(num < 0)
            expansion.push_back('-');
        int absolute = abs(num);
        while(absolute != 0)
        {
            int reminder = absolute % 7;
            expansion.push_back(reminder + '0');
            absolute -= reminder;
            absolute /= 7;
        }
        
        for(int l = expansion[0] == '-' ? 1 : 0, r = expansion.size() - 1; l < r; ++l, --r)
            swap(expansion[l], expansion[r]);
            
        return expansion;
    }
};
