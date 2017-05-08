/*
    Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
    Example:
    Input: s = "abcdefg", k = 2
    Output: "bacdfeg"
    Restrictions:
    The string consists of lower English letters only.
    Length of the given string and k will in the range [1, 10000]
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        for(int start = 0; start < size; start += 2 * k)
        {
            int end = min(size - 1, start + 2 * k - 1);
            if(end - start + 1 < k)
                reverseStringByIndex(s, start, end);
            else
                reverseStringByIndex(s, start, start + k - 1);
        }
        
        return s;
    }
    
private:
    void reverseStringByIndex(string& s, int start, int end)
    {
        while(start < end)
            swap(s[start++], s[end--]);
    }
};
