/*
    Given an array consists of non-negative integers, 
    your task is to count the number of triplets chosen 
    from the array that can make triangles if we take them as side lengths of a triangle.

    Example 1:
    Input: [2,2,3,4]
    Output: 3
    Explanation:
    Valid combinations are: 
    2,3,4 (using the first 2)
    2,3,4 (using the second 2)
    2,2,3
    Note:
    The length of the given array won't exceed 1000.
    The integers in the given array are in the range of [0, 1000].
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        
        int count = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = size - 1; i >= 2 && nums[i] != 0; --i)
        {
            for(int j = i - 1; j >= 1 && nums[j] != 0; --j)
            {
                int diff = nums[i] - nums[j];
                
                vector<int>::iterator end = nums.begin() + j;
                vector<int>::iterator it = upper_bound(nums.begin(), end, diff);
                count += end - it;
            }
        }
        
        return count;
    }
};
