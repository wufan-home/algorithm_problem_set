/*
  Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
  the contiguous subarray [4,−1,2,1] has the largest sum = 6.

  More practice:
  If you have figured out the O(n) solution, 
  try coding another solution using the divide and conquer approach, which is more subtle.

  Solution:
  1. Use the dynamic programming method.
*/

int maxSubArray(vector<int>& nums) {
        if(nums.empty())
    		return INT_MIN;
    
    	int max_sum = INT_MIN;
    	int sum = 0;
    	for(int front = 0; front < nums.size(); ++front)
    	{
    		sum += nums[front];
    		max_sum = max(max_sum, sum);
    		if(sum < 0)
    			sum = 0;
    	}
    
    	return max_sum;
}
