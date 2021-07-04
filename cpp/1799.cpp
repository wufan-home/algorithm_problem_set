/*
    You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

    In the ith operation (1-indexed), you will:

        Choose two elements, x and y.
        Receive a score of i * gcd(x, y).
        Remove x and y from nums.

    Return the maximum score you can receive after performing n operations.

    The function gcd(x, y) is the greatest common divisor of x and y.



    Example 1:

    Input: nums = [1,2]
    Output: 1
    Explanation: The optimal choice of operations is:
    (1 * gcd(1, 2)) = 1

    Example 2:

    Input: nums = [3,4,6,8]
    Output: 11
    Explanation: The optimal choice of operations is:
    (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

    Example 3:

    Input: nums = [1,2,3,4,5,6]
    Output: 14
    Explanation: The optimal choice of operations is:
    (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14



    Constraints:

        1 <= n <= 7
        nums.length == 2 * n
        1 <= nums[i] <= 106
        
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 1, 0, 3, 2, 0, 0, 1, 4, 0, 2, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 

*/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<vector<int>> dp(1 << (2 * n), vector<int>(n + 1));
        int ans = dpf(nums, dp, (1 << (2 * n)) - 1, n);
        return ans;
    }
    
private:
    int dpf(vector<int>& nums, vector<vector<int>>& dp, int mask, int step) {
        if (mask == 0 || step == 0) {
            return 0;
        }
        
        if (dp[mask][step]){
            return dp[mask][step];
        }

        int& ans = dp[mask][step];
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if ((mask & (1 << i)) && (mask & (1 << j))) {
                    int newMask = (mask ^ (1 << i) ^ (1 << j));
                    ans = max(ans, step * gcd(nums[i], nums[j]) + dpf(nums, dp, newMask, step - 1));
                }
            }
        }
        
        return ans;
    }
};
