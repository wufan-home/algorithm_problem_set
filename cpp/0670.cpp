/*
    Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
    Return the maximum valued number you could get.

    Example 1:
    Input: 2736
    Output: 7236
    Explanation: Swap the number 2 and the number 7.
    Example 2:
    Input: 9973
    Output: 9973
    Explanation: No swap.
*/

class Solution {
public:
    int maximumSwap(int num) {
        if(num == 0)
            return 0;
        
        string nstr = to_string(num);
        for(int i = 0; i < nstr.size() - 1; ++i)
        {
            char digit = nstr[i];
            int index = i;
            for(int j = i + 1; j < nstr.size(); ++j)
            {
                if(nstr[j] >= digit)
                {
                    index = j;
                    digit = nstr[j];
                }
            }
            
            if(digit != nstr[i])
            {
                swap(nstr[i], nstr[index]);
                return atoi(nstr.c_str());
            }
        }
        
        return num;
    }
};
