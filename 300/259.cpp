/*
    Given an array of n integers nums and a target, 
    find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
    For example, given nums = [-2, 0, 1, 3], and target = 2.
    Return 2. Because there are two triplets which sums are less than 2:
    [-2, 0, 1]
    [-2, 0, 3]
    Follow up:
    Could you solve it in O(n2) runtime?
*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
            
        sort(nums.begin(), nums.end());
        
        int count = 0;
        for(int first = nums.size() - 1; first >= 2; --first)
        {
            int target1 = target - nums[first];
            for(int r = first - 1; r >= 1; --r)
            {
                int target2 = target1 - nums[r];
                vector<int>::iterator it = lower_bound(nums.begin(), nums.begin() + r, target2);
                count += (it == nums.begin() ? 0 : it - nums.begin());
            }
        }
        
        return count;
    }
};
