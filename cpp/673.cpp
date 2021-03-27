/*
    Given an unsorted array of integers, find the number of longest increasing subsequence.

    Example 1:
    Input: [1,3,5,4,7]
    Output: 2
    Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
    Example 2:
    Input: [2,2,2,2,2]
    Output: 5
    Explanation: The length of longest continuous increasing subsequence is 1, 
    and there are 5 subsequences' length is 1, so output 5.
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        vector<int> seqNum(nums.size(), 0);
        vector<int> seqLen(nums.size(), 1);
        seqNum[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            int maxLen = 1;
            for(int j = i - 1; j >= 0; --j)
            {
                if(nums[j] < nums[i])
                {
                    if(maxLen < 1 + seqLen[j])
                    {
                        maxLen = 1 + seqLen[j];
                        seqNum[i] = seqNum[j];
                    }
                    else if(maxLen == 1 + seqLen[j])
                    {
                        seqNum[i] += seqNum[j];
                    }
                }
            }
            
            seqLen[i] = maxLen;
            if(seqNum[i] == 0)
                seqNum[i] = 1;
        }
        
        int maxLen = 1;
        unordered_map<int, int> count;
        for(int i = 0; i < seqNum.size(); ++i)
        {
            count[seqLen[i]] += seqNum[i];
            maxLen = max(maxLen, seqLen[i]);
        }
        
        
        return count[maxLen];
    }
};
