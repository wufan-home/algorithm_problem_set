/*
    A peak element is an element that is greater than its neighbors.

    Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

    The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

    You may imagine that num[-1] = num[n] = -∞.

    For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

    Note:
    Your solution should be in logarithmic complexity.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
            return INT_MIN;

        int n = nums.size();
        if(n == 1)
            return 0;
            
        if(nums[0] > nums[1])
            return 0;
        
        if(nums[n - 2] < nums[n - 1])
            return nums.size() - 1;
            
        for(int l = 0, r = n - 1; l < r;)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if(nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        
        return INT_MIN;
    }
};
