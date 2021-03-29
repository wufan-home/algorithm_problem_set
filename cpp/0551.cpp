/*
    You are given a string representing an attendance record for a student. The record only contains the following three characters:

    'A' : Absent.
    'L' : Late.
    'P' : Present.
    A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

    You need to return whether the student could be rewarded according to his attendance record.

    Example 1:
    Input: "PPALLP"
    Output: True
    Example 2:
    Input: "PPALLL"
    Output: False
*/

class Solution {
public:
    bool checkRecord(string s) {
        int numOfA = 0;
        for(int i = 0; i < s.size();)
        {
            if(s[i] == 'A')
            {
                if(++numOfA > 1)
                    return false;
            }

            if(i <= s.size() - 3 && s[i] == 'L')
            {
                if(s[i + 1] == 'L' && s[i + 2] == 'L')
                    return false;
                    
                i += s[i + 1] != 'L' ? 1 : (s[i + 2] != 'L' ? 2 : 3);
                continue;
            }
            
            ++i;
        }
        
        return true;
    }
};
