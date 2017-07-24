/*
    Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
    Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ? j), inclusive.

    Note:
    A naive algorithm of O(n2) is trivial. You MUST do better than that.

    Example:
    Given nums = [-2, 5, -1], lower = -2, upper = 2,
    Return 3.
    The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        mLower = lower;
        mUpper = upper;
        if(nums.empty())
            return 0;
        
        vector<long long> reform(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i)
            reform[i] = nums[i];
        
        return doCount(reform, 0, nums.size() - 1);
    }
    
private:
    
    int doCount(const vector<long long>& nums, int start, int end)
    {
        if(start == end)
            return nums[start] >= mLower && nums[start] <= mUpper;
        
        int mid = start + (end - start) / 2;
        int left = doCount(nums, start, mid);
        int right = doCount(nums, mid + 1, end);
        
        int count = left + right;
        
        long long sum = 0;
        for(int i = mid + 1; i <= end; ++i)
        {
            sum += nums[i];
            long long temp = sum;
            for(int j = mid; j >= start; --j)
            {
                temp += nums[j];
                if(temp >= mLower && temp <= mUpper)
                    ++count;
            }
        }
        
        return (int)count;
    }
    
    int mLower;
    int mUpper;
};
