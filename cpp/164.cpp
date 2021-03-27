/*
    Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

    Try to solve it in linear time/space.

    Return 0 if the array contains less than 2 elements.

    You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int maxDiff = 0;
        for(int i = 0; i < size - 1; ++i)
            maxDiff = max(maxDiff, nums[i + 1] - nums[i]);
        
        return maxDiff;
    }
};
