/*
    Given an array nums of integers, you can perform operations on the array.

    In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

    You start with 0 points. Return the maximum number of points you can earn by applying such operations.



    Example 1:

    Input: nums = [3,4,2]
    Output: 6
    Explanation: Delete 4 to earn 4 points, consequently 3 is also deleted.
    Then, delete 2 to earn 2 points.
    6 total points are earned.

    Example 2:

    Input: nums = [2,2,3,3,3,4]
    Output: 9
    Explanation: Delete 3 to earn 3 points, deleting both 2's and the 4.
    Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
    9 total points are earned.



    Constraints:

        1 <= nums.length <= 2 * 104
        1 <= nums[i] <= 104


*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            ++count[nums[i]];
        }
        
        int ans = 0;
        int prev = max(0, count[1]);
        int prev2 = 0;
        for (int i = 2; i < 10001; ++i) {
            ans = max(ans, max(count[i] * i + prev2, prev));
            prev2 = prev;
            prev = ans;
        }
        
        return ans;
    }
};
