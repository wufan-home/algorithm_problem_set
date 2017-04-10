/*
  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
  Find all unique quadruplets in the array which gives the sum of target.
  Note: The solution set must not contain duplicate quadruplets.
  For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
  A solution set is:
  [
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
  ]

  Solution: The key of the solution is to cut off the branches that do not need to reach.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());
       for(int i4 = nums.size() - 1; i4 >= 0; i4 = moveIndex(nums, i4, false))
           populateThreeSumForNewTarget(nums, 0, i4 - 1, target - nums[i4]);
       
       return results;
    }
private:
    int moveIndex(const vector<int>& nums, int index, bool moveForward)
    {
        if(nums.empty())
            return -1;
            
        if(moveForward)
            for(++index; index < nums.size() && nums[index - 1] == nums[index]; ++index) {}
        else
            for(--index; index >= 0 && nums[index] == nums[index + 1]; --index) {}
            
        return index;
    }
    
    void populateThreeSumForNewTarget(const vector<int>& nums, int start, int end, int target)
    {
        if(start >= end)
            return;
        
        for(int i3 = end; i3 >= start; i3 = moveIndex(nums, i3, false))
        {
            const int newTarget = target - nums[i3];
            for(int i1 = start, i2 = i3 - 1; i1 < i2; )
            {
                const int sum = nums[i1] + nums[i2];
                if(sum == newTarget)
                {
                    vector<int> result(1, nums[i1]);
                    result.push_back(nums[i2]);
                    result.push_back(nums[i3]);
                    result.push_back(nums[end + 1]);
                    results.push_back(result);
                    
                    i1 = moveIndex(nums, i1, true);
                    i2 = moveIndex(nums, i2, false);
                }
                else if(sum > newTarget)
                    i2 = moveIndex(nums, i2, false);
                else
                    i1 = moveIndex(nums, i1, true);
            }
        }
    }
    
    vector<vector<int>> results;
};
