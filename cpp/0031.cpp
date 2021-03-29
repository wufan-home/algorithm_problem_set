/*
  Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
  The replacement must be in-place, do not allocate extra memory.
  Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
  1,2,3 → 1,3,2
  3,2,1 → 1,2,3
  1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
            
        int index = nums.size() - 1;
        for(; index >= 0; --index)
        {
            if(index == 0 || nums[index] > nums[index - 1])
                break;
        }
        
        if(index > 0)
        {
            for(int i = nums.size() - 1; i >= index; --i)
            {
                if(nums[i] > nums[index - 1])
                {
                    swap(nums[i], nums[index - 1]);
                    break;
                }
            }
        }
        
        for(int l = index, r = nums.size() - 1; l < r; ++l, --r)
            swap(nums[l], nums[r]);
    }
};
