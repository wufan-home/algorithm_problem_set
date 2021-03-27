/*
    Given an unsorted array of integers, find the length of longest increasing subsequence.

    For example,
    Given [10, 9, 2, 5, 3, 7, 101, 18],
    The longest increasing subsequence is [2, 3, 7, 101], 
    therefore the length is 4. Note that there may be more than one LIS combination, 
    it is only necessary for you to return the length.

    Your algorithm should run in O(n2) complexity.

    Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
            
        vector<int> lengths(nums.size(), 0);
        lengths[0] = 1;
        int globalMaxLength = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            int maxLength = 1;
            for(int j = i - 1; j >= 0; --j)
            {
                if(nums[j] < nums[i])
                {
                    maxLength = max(maxLength, lengths[j] + 1);
                }
            }
            globalMaxLength = max(globalMaxLength, maxLength);
            lengths[i] = maxLength;
        }
        
        return globalMaxLength;
    }
};
