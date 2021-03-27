/*
    Given a positive integer, return its corresponding column title as appear in an Excel sheet.

    For example:

        1 -> A
        2 -> B
        3 -> C
        ...
        26 -> Z
        27 -> AA
        28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0)
        {
            int remind = n % 26;
            n /= 26;
            if(remind == 0 && n > 0)
            {
                remind = 26;
                --n;
            }
            
            res.push_back(remind + 'A' - 1);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
