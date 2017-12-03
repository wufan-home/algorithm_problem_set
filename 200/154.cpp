/*
    Follow up for "Find Minimum in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?
    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r)
        {
            if(nums[l] == nums[r])
                for(; r > l && nums[r] == nums[l]; --r) {}
            
            if(r == l)
                break;
            
            int mid = l + (r - l) / 2;
            for(; mid > l && nums[mid] == nums[mid - 1]; --mid) {}
            if(nums[mid] < nums[mid + 1] && (mid == l || nums[mid] < nums[mid - 1]))
                return nums[mid];
            else if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        
        return nums[l];
    }
};
