/*
    Given an array of integers and an integer k, 
    you need to find the total number of continuous subarrays whose sum equals to k.

    Example 1:
    Input:nums = [1,1,1], k = 2
    Output: 2
    Note:
    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size(), 0);
        sums[0] = nums[0];
        for(int i = 0; i < nums.size(); ++i)
            sums[i] = sums[i - 1] + nums[i];
        
        int count = 0;
        for(int i = sums.size() - 1; i >= 1; --i)
        {
            count += (sums[i] == k);
            for(int j = i - 1; j >= 0; --j)
                count += (sums[i] - sums[j] == k);
        }
        
        count += (nums[0] == k);
        
        return count;
    }
};
