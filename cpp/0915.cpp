/*
    Given an array nums, partition it into two (contiguous) subarrays left and right so that:

    Every element in left is less than or equal to every element in right.
    left and right are non-empty.
    left has the smallest possible size.

    Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.



    Example 1:

    Input: nums = [5,0,3,8,6]
    Output: 3
    Explanation: left = [5,0,3], right = [8,6]

    Example 2:

    Input: nums = [1,1,1,0,6,12]
    Output: 4
    Explanation: left = [1,1,1,0], right = [6,12]

    Note:

        2 <= nums.length <= 30000
        0 <= nums[i] <= 106
        It is guaranteed there is at least one way to partition nums as described.
        
    Solution II:
    
    This is a smart solution.
    
    First, keep a left maximum. 
    If a new element is smaller than the left maximum,
    it means all the elements on the left of the new element cannot be divided.
    Group them into one group.
*/

// Classical solution.
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int size = nums.size();
        vector<int> maximums(size, nums[0]);
        for (int i = 1; i < size; ++i) {
            maximums[i] = max(nums[i], maximums[i - 1]);
        }
        
        int ans = size;
        int minimum = INT_MAX;
        for (int j = nums.size() - 1; j > 0; --j) {
            minimum = min(minimum, nums[j]);
            if (minimum >= maximums[j - 1]) {
                ans = min(ans, j);
            }
        }
        
        return ans;
    }
};

// Smart solution.
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int size = nums.size();
        int leftMax = nums[0];
        int globalMax = nums[0];
        int ans = 1;
        for (int i = 1; i < size; ++i) {
            globalMax = max(nums[i], globalMax);
            if (nums[i] < leftMax) {
                ans = i + 1;
                leftMax = globalMax;
            }
        }
        return ans;
    }
};
