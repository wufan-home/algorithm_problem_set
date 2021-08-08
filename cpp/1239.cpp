/*
    Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

    Return the maximum possible length of s.



    Example 1:

    Input: arr = ["un","iq","ue"]
    Output: 4
    Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
    Maximum length is 4.
    Example 2:

    Input: arr = ["cha","r","act","ers"]
    Output: 6
    Explanation: Possible solutions are "chaers" and "acters".
    Example 3:

    Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
    Output: 26


    Constraints:

    1 <= arr.length <= 16
    1 <= arr[i].length <= 26
    arr[i] contains only lower case English letters.

    Ref: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/discuss/414172/PythonC%2B%2BJava-Set-Solution
*/

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for (auto& s : arr) {
            bitset<26> a;
            for (char c : s)
                a.set(c - 'a');
            int n = a.count();
            if (n < s.size()) continue;

            for (int i = dp.size() - 1; i >= 0; --i) {
                bitset c = dp[i];
                if ((c & a).any()) continue;
                dp.push_back(c | a);
                res = max(res, (int)c.count() + n);
            }
        }
        return res;
    }
};
