/*
	Given a sorted integer array without duplicates, return the summary of its ranges.

	Example 1:
	Input: [0,1,2,4,5,7]
	Output: ["0->2","4->5","7"]
	Example 2:
	Input: [0,2,3,4,6,8,9]
	Output: ["0","2->4","6","8->9"]
	
	Note: This problem is equivalent to the problem to find a consecutive sequence
	from an ordered array. 
	
	If the array is not ordered, the best way is to use the union-find if there is 
	memory allowance.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        nums.push_back(INT_MAX);
        int size = nums.size();
        for(int start = 0, end = 0, i = 1; i < size; ++i)
        {
            if(nums[i] == nums[end] + 1)
                ++end;
            else
            {
                res.push_back(to_string(nums[start]));
                if(end > start)
                {
                    res.back().append("->");
                    res.back().append(to_string(nums[end]));
                }
                start = i;
                end = i;
            }
        }
        nums.pop_back();
        
        return res;
    }
};
