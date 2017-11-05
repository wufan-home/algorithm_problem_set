/*
    Your are given an array of positive integers nums.

    Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

    Example 1:
    Input: nums = [10, 5, 2, 6], k = 100
    Output: 8
    Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
    Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
    Note:

    0 < nums.length <= 50000.
    0 < nums[i] < 1000.
    0 <= k < 10^6.
    
    讨论：这道题其实可有很多种变形，比如当数组的数字有负数和0该怎么做？或者求的不是子数组，而是子序列该怎么做，
    子序列的话就可以排序啦，当然还是需要都是正数，才有排序的意思，博主觉得如果有负数和0，
    是不是只能暴力破解了，或者使用Maximum Product Subarray中的方法？再有一种的变形就是求子数组或子序列乘积刚好等于k，
    这就跟Subarray Sum Equals K和Maximum Size Subarray Sum Equals k这两题中使用的方法类似吧，建立子数组和其乘积之间的映射来快速找到。
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        
        int res = 0;
        long long prod = 1;
        int l = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            prod *= nums[i];
            while(prod >= k)
                prod /= nums[l++];
            
            res += i - l + 1;
        }
        
        return res;
    }
};
