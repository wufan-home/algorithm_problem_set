/*
    You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

    You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

    Choose one integer x from either the start or the end of the array nums.
    Add multipliers[i] * x to your score.
    Remove x from the array nums.
    Return the maximum score after performing m operations.



    Example 1:

    Input: nums = [1,2,3], multipliers = [3,2,1]
    Output: 14
    Explanation: An optimal solution is as follows:
    - Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
    - Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
    - Choose from the end, [1], adding 1 * 1 = 1 to the score.
    The total score is 9 + 4 + 1 = 14.
    Example 2:

    Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
    Output: 102
    Explanation: An optimal solution is as follows:
    - Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
    - Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
    - Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
    - Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
    - Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
    The total score is 50 + 15 - 9 + 4 + 42 = 102.


    Constraints:

    n == nums.length
    m == multipliers.length
    1 <= m <= 103
    m <= n <= 105
    -1000 <= nums[i], multipliers[i] <= 1000
    
    [1,2,3]
    [3,2,1]

    0, 9, 0, 0, 
    3, 0, 0, 0, 
    0, 0, 0, 0, 
    0, 0, 0, 0, 

    0, 9, 13, 0, 
    3, 11, 0, 0, 
    7, 0, 0, 0, 
    0, 0, 0, 0, 

    0, 9, 13, 14, 
    3, 11, 14, 0, 
    7, 13, 0, 0, 
    10, 0, 0, 0, 

    [-5,-3,-3,-2,7,1]
    [-10,-5,3,4,6]

    0, -10, 0, 0, 0, 0, 
    50, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 

    0, -10, -45, 0, 0, 0, 
    50, 45, 0, 0, 0, 0, 
    65, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 

    0, -10, -45, -51, 0, 0, 
    50, 45, 66, 0, 0, 0, 
    65, 68, 0, 0, 0, 0, 
    56, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 

    0, -10, -45, -51, -63, 0, 
    50, 45, 66, 58, 0, 0, 
    65, 68, 96, 0, 0, 0, 
    56, 60, 0, 0, 0, 0, 
    48, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 

    0, -10, -45, -51, -63, -81, 
    50, 45, 66, 58, 40, 0, 
    65, 68, 96, 84, 0, 0, 
    56, 60, 102, 0, 0, 0, 
    48, 54, 0, 0, 0, 0, 
    90, 0, 0, 0, 0, 0, 


*/

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        int ans = INT_MIN;
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int k = 1; k <= m; ++k) {
            for (int i = 0, j = k - i; i <= k; ++i, --j) {
                dp[i][j] = max((i == 0 ? INT_MIN : dp[i - 1][j] + nums[i - 1] * multipliers[k - 1]), 
                               (j == 0 ? INT_MIN : dp[i][j - 1] + nums[n - j] * multipliers[k - 1]));
            }
        }
        
        for (int i = 0; i <= m; ++i) {
            ans = max(ans, dp[i][m - i]);
        }
        
        return ans;
    }
};
