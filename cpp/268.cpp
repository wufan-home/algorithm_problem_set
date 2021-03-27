/*
    Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

    For example,
    Given nums = [0, 1, 3] return 2.

    Note:
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
    
    Note: This is the best way. Apply this problem to a string.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        return n * (1 + n) / 2 - (int)sum;
    }
};
