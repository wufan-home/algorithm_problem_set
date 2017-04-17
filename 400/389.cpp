/*
    Given two strings s and t which consist of only lowercase letters.
    String t is generated by random shuffling string s and then add one more letter at a random position.
    Find the letter that was added in t.
    Example:
    Input:
    s = "abcd"
    t = "abcde"
    Output:
    e
    Explanation:
    'e' is the letter that was added.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> char_hash_size(26, 0);
        
        for(int i = 0; i < s.size(); ++i)
            ++char_hash_size[s[i] - 'a'];
        
        int cur = 0;
        for(; cur < s.size(); ++cur)
        {
            if(char_hash_size[t[cur] - 'a'] == 0)
                return t[cur];
            
            --char_hash_size[t[cur] - 'a'];
        }
        
        return t[cur];
    }
};
