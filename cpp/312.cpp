/*
    Given n balloons, indexed from 0 to n-1. 
    Each balloon is painted with a number on it represented by array nums. 
    You are asked to burst all the balloons. 
    If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
    Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

    Find the maximum coins you can collect by bursting the balloons wisely.

    Note: 
    (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
    (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

    Example:

    Given [3, 1, 5, 8]

    Return 167

        nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
       coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        
        vector<vector<int>> dp(size, vector<int>(size, 0)); 
        for(int len = 1; len <= size; ++len)
        {
            for(int l = 0; l <= size - len; ++l)
            {
                int r = l + len - 1;
                int leftmost = l == 0 ? 1 : nums[l - 1];
                int rightmost = r == size - 1 ? 1 : nums[r + 1];
                
                for(int k = l; k <= r; ++k)
                {
                    int left = k == l ? 0 : dp[l][k - 1];
                    int right = k == r ? 0 : dp[k + 1][r];
                    dp[l][r] = max(dp[l][r], leftmost * rightmost * nums[k] + left + right);
                }
            }
        }
        
        return dp[0][size - 1];
    }
};
