/*
    Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

    Example 1:

    Input:
    A: [1,2,3,2,1]
    B: [3,2,1,4,7]
    Output: 3
    Explanation: 
    The repeated subarray with maximum length is [3, 2, 1].



    Note:

        1 <= len(A), len(B) <= 1000
        0 <= A[i], B[i] < 100

*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        
        vector<vector<int>> dp(sizeA, vector<int>(sizeB, 0));
        
        int res = 0;
        for (int i = 0; i <sizeA; ++i) {
            for (int j = 0; j < sizeB; ++j) {
                if (A[i] == B[j]) {
                    dp[i][j] = (i == 0 || j == 0 ? 0 : dp[i - 1][j - 1]) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        
        return res;
    }
};
