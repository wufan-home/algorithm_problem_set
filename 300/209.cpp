/*
	Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

	For example, given the array [2,3,1,2,4,3] and s = 7,
	the subarray [4,3] has the minimal length under the problem constraint.

	click to show more practice.

	More practice:
	If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
            
        int minLen = INT_MAX;
        int sum = 0;
        for(int l = 0, r = 0; r < nums.size(); ++r)
        {
            sum += nums[r];
            if(sum < s)
                continue;
            
            for(; l <= s && sum >= s; ++l)
            {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};
