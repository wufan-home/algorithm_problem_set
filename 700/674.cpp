/*
    Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

    Example 1:
    Input: [1,3,5,4,7]
    Output: 3
    Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
    Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
    Example 2:
    Input: [2,2,2,2,2]
    Output: 1
    Explanation: The longest continuous increasing subsequence is [2], its length is 1.
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int maxLen = 1;
        vector<int> lengths(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i - 1] < nums[i])
            {
                lengths[i] = lengths[i - 1] + 1;
                maxLen = max(maxLen, lengths[i]);
            }
        }
        
        
        return maxLen;
    }
};
