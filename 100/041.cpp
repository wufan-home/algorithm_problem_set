/*
  Given an unsorted integer array, find the first missing positive integer.
  For example,
  Given [1,2,0] return 3,
  and [3,4,-1,1] return 2.
  Your algorithm should run in O(n) time and uses constant space.
  Show Tags
  Show Similar Problems
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int maxNumber = nums.size();
        
        for(int i = 0; i < maxNumber; ++i)
        {
            while(i != nums[i] - 1)
            {
                if(nums[i] < 1 || nums[i] > maxNumber || nums[i] == nums[nums[i] - 1])
                {
                    nums[i] = -1;
                    break;
                }
                
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        int firstMissingPositive = 1;
        for(; firstMissingPositive <= maxNumber; ++firstMissingPositive)
        {
            if(nums[firstMissingPositive - 1] == -1)
                break;
        }
        
        return firstMissingPositive;
    }
};
