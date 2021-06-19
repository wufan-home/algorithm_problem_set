/*
    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

    Return the length of the longest substring containing the same letter you can get after performing the above operations.



    Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.

    Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.



    Constraints:

        1 <= s.length <= 105
        s consists of only uppercase English letters.
        0 <= k <= s.length


*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = s.size();
        int ans = 0;
        vector<int> count(26, 0);
        int maxRepeats = 0;
        for (int l = 0, r = 0; r < length; ++r) {
            maxRepeats = max(maxRepeats, ++count[s[r] - 'A']);
            while (r - l + 1 - maxRepeats > k) {
                --count[s[l++] - 'A'];
                for (int i = 0; i < 26; ++i) {
                    maxRepeats = max(maxRepeats, count[i]);
                }
            }
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
