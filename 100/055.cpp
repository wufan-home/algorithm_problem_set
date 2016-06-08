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

#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
		return true;

	int reachable = 0;
	int size = nums.size();
	for(int i = 0; i <= min(size - 1, reachable); ++i)
		reachable = max(reachable, i + nums[i]);

	return reachable >= size - 1;
}
