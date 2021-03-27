/*
    Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

    You need to find the shortest such subarray and output its length.

    Example 1:
    Input: [2, 6, 4, 8, 10, 9, 15]
    Output: 5
    Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
    Note:
    Then length of the input array is in range [1, 10,000].
    The input array may contain duplicates, so ascending order here means <=.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
            
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        
        int left = -1;
        int right = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != sortedNums[i] && left == -1)
            {
                left = i;
                break;
            }
        }
        
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            if(nums[i] != sortedNums[i] && right == -1)
            {
                right = i;
                break;
            }
        }
        
        return left == -1 ? 0 : right - left + 1;
    }
};
