/*
	Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

	Example:
	Given nums = [-2, 0, 3, -5, 2, -1]

	sumRange(0, 2) -> 1
	sumRange(2, 5) -> -1
	sumRange(0, 5) -> -3
	Note:
	You may assume that the array does not change.
	There are many calls to sumRange function.
*/

class NumArray {
public:
    NumArray(const vector<int>& nums) {
        if(!nums.empty())
        {
            partial_sums.resize(nums.size(), 0);
            partial_sums[0] = nums[0];
            for(int i = 1; i < nums.size(); ++i)
                partial_sums[i] = nums[i] + partial_sums[i - 1];
        }
    }

    int sumRange(int i, int j) {
            return partial_sums[j] - (i == 0 ? 0 : partial_sums[i - 1]);
    }
private:
    vector<int> partial_sums;
};
