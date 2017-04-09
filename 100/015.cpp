/*
  Given an array S of n integers, are there elements a, b, c in S 
  such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
  Note: The solution set must not contain duplicate triplets.
  For example, given array S = [-1, 0, 1, 2, -1, -4],
  A solution set is:
  [
    [-1, 0, 1],
    [-1, -1, 2]
  ]
*/

class Solution {
public:
    int moveIndex(const vector<int>& nums, int index, const bool moveForward)
    {
        if(moveForward)
            for(++index; index < nums.size() && nums[index] == nums[index - 1]; ++index) {}
        else
            for(--index; index >= 0 && nums[index] == nums[index + 1]; --index) {}
            
        return index;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sums;
        
        sort(nums.begin(), nums.end());
        for(int i3 = nums.size() - 1; i3 >= 0;)
        {
            int target = (-1) * nums[i3];
            
            for(int i1 = 0, i2 = i3 - 1; i1 < i2;)
            {
                if(nums[i1] + nums[i2] == target)
                {
                    vector<int> sum(1, nums[i1]);
                    sum.push_back(nums[i2]);
                    sum.push_back(nums[i3]);
                    sums.push_back(sum);
                    
                    i1 = moveIndex(nums, i1, true);
                    i2 = moveIndex(nums, i2, false);
                }
                else if(nums[i1] + nums[i2] > target)
                    i2 = moveIndex(nums, i2, false);
                else
                    i1 = moveIndex(nums, i1, true);
            }
            
            i3 = moveIndex(nums, i3, false);
        }
        
        return sums;
    }
};
