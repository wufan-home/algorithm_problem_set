/*
   Given an array of non-negative integers, you are initially positioned at the first index of the array.

   Each element in the array represents your maximum jump length at that position.

   Determine if you are able to reach the last index.

   For example:
   A = [2,3,1,1,4], return true.

   A = [3,2,1,0,4], return false. 

   Solution:
   Update the farthest reachable position on each step.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(maxReachable >= nums.size() - 1 || i > maxReachable)
                break;
                
            maxReachable = max(maxReachable, i + nums[i]);
        }
        
        return maxReachable >= nums.size() - 1;
    }
};
