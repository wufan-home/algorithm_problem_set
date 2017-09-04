/*
    You are given an integer array nums and you have to return a new counts array. 
    The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

    Example:

    Given nums = [5, 2, 6, 1]

    To the right of 5 there are 2 smaller elements (2 and 1).
    To the right of 2 there is only 1 smaller element (1).
    To the right of 6 there is 1 smaller element (1).
    To the right of 1 there is 0 smaller element.
    Return the array [2, 1, 1, 0].
*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> sorted(nums.size(), INT_MIN);
        for(int i = nums.size() - 1, endIndex = 0; i >= 0; --i)
        {
            res[i] = lower_bound(sorted.begin(), sorted.begin() + endIndex, nums[i]) - sorted.begin();
            sorted[endIndex++] = nums[i];
            for(int j = endIndex - 1; j > 0; --j)
            {
                if(sorted[j] >= sorted[j - 1])
                    break;
                
                swap(sorted[j], sorted[j - 1]);
            }
        }
        
        return res;
    }
};
