/*
    Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

    Example 1:
    Input:
    nums = [1,3,1]
    k = 1
    Output: 0 
    Explanation:
    Here are all the pairs:
    (1,3) -> 2
    (1,1) -> 0
    (3,1) -> 2
    Then the 1st smallest distance pair is (1,1), and its distance is 0.
    Note:
    2 <= len(nums) <= 10000.
    0 <= nums[i] < 1000000.
    1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int l = nums[len - 1] - nums[0];
        for(int i = 1; i < len; ++i)
            l = min(l, nums[i] - nums[i - 1]);
        
        int r = nums[len - 1] - nums[0];
        
        while(l < r)
        {
            int mid = l + ((r - l) >> 1);
            if(countPairs(nums, mid) < k)
                l = mid + 1;
            else
                r = mid;
        }
        
        return l;
    }
    
private:
    int countPairs(const vector<int>& nums, int mid)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
            res += upper_bound(nums.begin(), nums.end(), nums[i] + mid) - (nums.begin() + i + 1);
        return res;
    }
};
