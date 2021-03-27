/*
  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  You are given a target value to search. If found in the array return its index, otherwise return -1.
  You may assume no duplicate exists in the array.

  Solution: Binary search. We first distinguish which part is a rotate array.
  For the sorted part, use the usual binary search.
  For the rotated part, use the recursive part.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
            
        for(int l = 0, r = nums.size() - 1; l <= r;)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;
            
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
        
        return -1;
    }
};
