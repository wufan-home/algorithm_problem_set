/*
	Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

	Note:
	You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
	The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int w = m + n - 1, i1 = m - 1, i2 = n - 1; w >= 0; --w)
        {
            nums1[w] = (i1 < 0 ? INT_MIN : nums1[i1]) > (i2 < 0 ? INT_MIN : nums2[i2]) ? nums1[i1--] : nums2[i2--];
        }
    }
};
