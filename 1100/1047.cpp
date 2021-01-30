/*
    Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

    We repeatedly make duplicate removals on S until we no longer can.

    Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.



    Example 1:

    Input: "abbaca"
    Output: "ca"
    Explanation: 
    For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".



    Note:

        1 <= S.length <= 20000
        S consists only of English lowercase letters.
*/

class Solution {
public:
    string removeDuplicates(string S) {
        int len = S.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (S[j] != '*') {
                    if (S[i] == S[j]) {
                        S[i] = '*';
                        S[j] = '*';
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            
            if (i < len - 1 && S[i] == S[i + 1]) {
                S[i] = '*';
                S[i + 1] = '*';
            }
        }
        
        string res;
        for (int i = 0; i < len; ++i) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                res.push_back(S[i]);
            }
        }
        
        return res;
    }
};
