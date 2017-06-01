/*
    Follow up for "Search in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?
    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Write a function to determine if a given target is in the array.

    The array may contain duplicates.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
            
        for(int l = 0, r = nums.size() - 1; l <= r;)
        {
            for(; r > l && nums[r] == nums[r - 1]; --r) {}
            for(; l < r && nums[l] == nums[l + 1]; ++l) {}
            if(l > r)
                return nums[r] == target;

            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] < nums[r])
            {
                if(nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
            }
            else 
            {
                if(nums[l] <= target && target < nums[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
        }
        
        return false;
    }
};
