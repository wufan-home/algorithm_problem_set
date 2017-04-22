/*
    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
    Find the minimum element.
    You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size() - 1])
                return nums[0];
        
        for(int s = 0, e = nums.size() - 1; s < e;)
        {
            int mid = s + (e - s) / 2;
            if(mid == s)
                return min(nums[s], nums[e]);
            else if(nums[mid] < nums[e])
                e = mid;
            else
                s = mid;
        }
        
        return nums[0];
    }
};
