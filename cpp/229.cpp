/*
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
    The algorithm should run in linear time and in O(1) space.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty())
            return vector<int>();
        
        int v1 = 0;
        int f1 = 0;
        int v2 = 0;
        int f2 = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == v1)
                ++f1;
            else if(nums[i] == v2)
                ++f2;
            else if(f1 == 0)
            {
                v1 = nums[i];
                ++f1;
            }
            else if(f2 == 0)
            {
                v2 = nums[i];
                ++f2;
            }
            else
            {
                --f1;
                --f2;
            }
        }
        
        f1 = 0;
        f2 = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == v1)
                ++f1;
            else if(nums[i] == v2)
                ++f2;
        }
        
        vector<int> res;
        if(f1 > nums.size() / 3) 
            res.push_back(v1);
        
        if(f2 > nums.size() / 3)
            res.push_back(v2);
        
        return res;
    }
};
