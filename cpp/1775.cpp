/*
    You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values in the arrays are between 1 and 6, inclusive.

    In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

    Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.



    Example 1:

    Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
    Output: 3
    Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
    - Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
    - Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
    - Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].

    Example 2:

    Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
    Output: -1
    Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.

    Example 3:

    Input: nums1 = [6,6], nums2 = [1]
    Output: 3
    Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
    - Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
    - Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
    - Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].



    Constraints:

        1 <= nums1.length, nums2.length <= 105
        1 <= nums1[i], nums2[i] <= 6


*/

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        if (6 * min(size1, size2) < max(size1, size2)) {
            return -1;
        }
        
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 > sum2) {
            return minOperations(nums2, nums1);
        }
        
        if (sum1 == sum2) {
            return 0;
        }
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.rbegin(), nums2.rend());
        
        int ans = 0;
        int total = sum2 - sum1;
        for (int i1 = 0, i2 = 0; sum1 < sum2; ++ans) {
            int diff1 = (i1 < size1 ? 6 - nums1[i1] : 0);
            int diff2 = (i2 < size2 ? nums2[i2] - 1 : 0);
            if (diff1 >= diff2) {
                sum1 += diff1;
                ++i1;
            }
            else {
                sum2 -= diff2;
                ++i2;
            }
        }
        
        return ans;
    }
};
