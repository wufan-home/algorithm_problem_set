/*
    A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

    Example 1:

    Input: S = "ababcbacadefegdehijhklij"
    Output: [9,7,8]
    Explanation:
    The partition is "ababcbaca", "defegde", "hijhklij".
    This is a partition so that each letter appears in at most one part.
    A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.


    Note:

    S will have length in range [1, 500].
    S will consist of lowercase English letters ('a' to 'z') only.

*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        
        int length = S.size();
        
        // Two pointers
        vector<int> maxRightIndex(26, -1);
        for (int i = 0; i < length; ++i) {
            maxRightIndex[S[i] - 'a'] = max(maxRightIndex[S[i] - 'a'], i);
        }
        
        int leftEnd = -1;
        int rightEnd = -1;
        for(int i = 0; i < length; ++i) {
            rightEnd = max(rightEnd, maxRightIndex[S[i] - 'a']);
            if (i == rightEnd) {
                res.push_back(i - leftEnd);
                leftEnd = i;
            }
        }
        
        return res;
    }
};
