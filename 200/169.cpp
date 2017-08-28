/*
    Given an array of size n, find the majority element. 
    The majority element is the element that appears more than ⌊ n/2 ⌋ times.

    You may assume that the array is non-empty and the majority element always exist in the array.
    
    Solution: The vote algorithm.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxElement = INT_MIN;
        int freq = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != maxElement)
            {
                if(freq == 0)
                {
                    maxElement = nums[i];
                    freq = 1;
                }
                else
                    --freq;
            }
            else
                ++freq;
        }
        
        return maxElement;
    }
};
