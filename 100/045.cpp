/*
   Given an array of non-negative integers, you are initially positioned at the first index of the array.
   Each element in the array represents your maximum jump length at that position.
   Your goal is to reach the last index in the minimum number of jumps.
   For example:
   Given array A = [2,3,1,1,4]
   The minimum number of jumps to reach the last index is 2. 
   (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
   Note:
   You can assume that you can always reach the last index.

   Solution: Only the start position with maximal steps that reaches over the current farthest point
   can be a candidate of the solution. Update all minimal steps that reaches the following positions
   of the position i and the farthest length we can reach. Exit the program if the last point is visited.
*/

int jump(vector<int>& nums)
{
        if(nums.size() <= 1)
		return 0;
            
        int size = nums.size();
        vector<int> steps(size, INT_MAX);
        steps[0] = 0;
        int max_reach = 0;
        for(int i = 0; i < size; ++i)
        {
		if(nums[i] + i <= max_reach)
			continue;
            
		max_reach = max(max_reach, nums[i] + i);
		for(int j = 1; j <= nums[i] && i + j < size; ++j)
			steps[i + j] = min(steps[i + j], steps[i] + 1);

		if(max_reach >= size)
			break;
        }
        
        return steps[size - 1] == INT_MAX ? -1 : steps[size - 1];
}
