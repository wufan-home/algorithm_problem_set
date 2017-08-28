/*
    Given an array of size n, find the majority element. 
    The majority element is the element that appears more than ⌊ n/2 ⌋ times.

    You may assume that the array is non-empty and the majority element always exist in the array.
    
    Solution: The vote algorithm. The nature of this algorithm is that the addition is order not matter.
    This means that it is equivelant that to increase the freq before or afterhand.
    The majority element (the maximal freq) will always be left, since its freq is bigger than 
    the sum of the freqs of all other elements.
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
