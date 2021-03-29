/*
    We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

    Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

    Example 1:
    Input: [1,3,2,2,5,2,3,7]
    Output: 5
    Explanation: The longest harmonious subsequence is [3,2,2,2,3].
    Note: The length of the input array will not exceed 20,000.
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(count.find(nums[i]) == count.end())
                count[nums[i]] = 0;
                
            ++count[nums[i]];
        }
        
        int maxLen = INT_MIN;
        for(unordered_map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
        {
            int key = it->first;
            if(count.find(key + 1) != count.end())
                maxLen = max(maxLen, count[key] + count[key + 1]);
                
            if(count.find(key - 1) != count.end())
                maxLen = max(maxLen, count[key] + count[key - 1]);
        }
        
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};
