/*
    Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

    Please note that the string does not contain any non-printable characters.

    Example:

    Input: "Hello, my name is John"
    Output: 5
*/

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool found = false;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != ' ' && found == false)
            {
                found = true;
                ++count;
            }
            else if(s[i] == ' ' && found == true)
                found = false;
        }
        
        return count;
    }
};
