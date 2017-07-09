/*
    Given an integer array, find three numbers whose product is maximum and output the maximum product.

    Example 1:
    Input: [1,2,3]
    Output: 6
    Example 2:
    Input: [1,2,3,4]
    Output: 24
    Note:
    The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
    Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        if(nums.size() < 3)
            return maxProd;
        
        int maxTwoProds = nums[1] * nums[0];
        
        int minTwoProds = nums[1] * nums[0];
        
        int maxValue = max(nums[0], nums[1]);
        int minValue = min(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i)
        {
            maxProd = max(maxProd, max(nums[i] * maxTwoProds, nums[i] * minTwoProds));
            int twoProd1 = nums[i] * maxValue;
            int twoProd2 = nums[i] * minValue;
            
            maxTwoProds = max(maxTwoProds, max(twoProd1, twoProd2));
            minTwoProds = min(minTwoProds, min(twoProd1, twoProd2));
            
            maxValue = max(maxValue, nums[i]);
            minValue = min(minValue, nums[i]);
        }
        
        return maxProd;
    }
};
