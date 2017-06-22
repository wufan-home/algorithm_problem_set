/*
   Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

   Example:
   (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
   (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

   Note:
   You may assume all input has valid answer.

   Follow Up:
   Can you do it in O(n) time and/or in-place with O(1) extra space? 
 */

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
            
        sort(nums.begin(), nums.end());
        int half = nums.size() / 2 + (nums.size() % 2 == 0 ? -1 : 0);
        for(int l = 0, r = half; l < r; ++l, --r)
            swap(nums[l], nums[r]);
            
        for(int l = half + 1, r = nums.size() - 1; l < r; ++l, --r)
            swap(nums[l], nums[r]);   
            
        for(int write = 1, read = half + 1; write < read && read < nums.size(); write += 2, ++read)
        {
            for(int j = read; j > write; --j)
                swap(nums[j - 1], nums[j]);
        }
    }
};
