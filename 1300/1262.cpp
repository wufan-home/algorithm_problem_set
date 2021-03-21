/*
    Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

 

    Example 1:

    Input: nums = [3,6,5,1,8]
    Output: 18
    Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

    Example 2:

    Input: nums = [4]
    Output: 0
    Explanation: Since 4 is not divisible by 3, do not pick any number.

    Example 3:

    Input: nums = [1,2,3,4,4]
    Output: 12
    Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).



    Constraints:

        1 <= nums.length <= 4 * 10^4
        1 <= nums[i] <= 10^4


*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int size = nums.size();
        vector<int> r(3, 0);
        for (int i = 0; i < size; ++i) {
            int update_r0 = 0;
            int update_r1 = 0;
            int update_r2 = 0;
            for (int j = 0; j < 3; ++j) {
                if ((r[j] + nums[i]) % 3 == 0) {
                    update_r0 = max(update_r0, r[j] + nums[i]);
                } else if ((r[j] + nums[i]) % 3 == 1) {
                    update_r1 = max(update_r1, r[j] + nums[i]);
                } else {
                    update_r2 = max(update_r2, r[j] + nums[i]);
                }
            }
            
            r[0] = max(r[0], update_r0);
            r[1] = max(r[1], update_r1);
            r[2] = max(r[2], update_r2);
        }
        
        return r[0];
    }
};
