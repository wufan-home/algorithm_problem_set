/*
    Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

    Find all the elements that appear twice in this array.

    Could you do it without extra space and in O(n) runtime?

    Example:
    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        if(nums.empty())
            return duplicates;
            
        for(int i = 0; i < nums.size(); ++i)
        {
            while(i != nums[i] - 1)
            {
                if(nums[i] == 0)
                    break;

                if(nums[nums[i] - 1] == nums[i])
                {
                    duplicates.push_back(nums[i]);
                    nums[i] = 0;
                    break;
                }
                
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        
        return duplicates;
    }
};
