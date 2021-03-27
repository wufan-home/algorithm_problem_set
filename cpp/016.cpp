/*
  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
  Return the sum of the three integers. You may assume that each input would have exactly one solution.
  For example, given array S = {-1 2 1 -4}, and target = 1.
  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int moveIndex(const vector<int>& nums, int index, const bool moveForward)
    {
        if(nums.empty())
            return -1;

        if(moveForward)
            for(++index; index < nums.size() && nums[index] == nums[index - 1]; ++index) {}
        else
            for(--index; index >= 0 && nums[index] == nums[index + 1]; --index) {}
            
        return index;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int minDifference = INT_MAX;
        int desiredSum = INT_MIN; 
        
        if(nums.empty())
            return minDifference;
            
        sort(nums.begin(), nums.end());
        for(int i3 = nums.size() - 1; i3 > 0; i3 = moveIndex(nums, i3, false))
        {
            for(int i1 = 0, i2 = i3 - 1; i1 < i2;)
            {
                const int sum = nums[i1] + nums[i2] + nums[i3];
                if(sum == target)
                    return sum;
                    
                const int difference = (int) abs(target - sum);
                if(difference < minDifference)
                {
                    minDifference = min(minDifference, difference);
                    desiredSum = sum;
                }
                
                
                if(sum > target)
                    i2 = moveIndex(nums, i2, false);
                else
                    i1 = moveIndex(nums, i1, true);
            }
        }
        
        return desiredSum;
    }
};
