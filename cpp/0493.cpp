/*
    Given an integer array nums, return the number of reverse pairs in the array.

    A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].



    Example 1:

    Input: nums = [1,3,2,3,1]
    Output: 2

    Example 2:

    Input: nums = [2,4,3,5,1]
    Output: 3



    Constraints:

        1 <= nums.length <= 5 * 104
        -231 <= nums[i] <= 231 - 1


*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<vector<long long>> hold;
        int n = nums.size();
        for (int i = 0; i < n; ++i) hold.push_back(vector<long long>({static_cast<long long>(nums[i]), i})); // "zip" the nums with their indices
        vector<int> count(n, 0);
        sort_count(hold.begin(), hold.end(), count);
        return accumulate(count.begin(), count.end(), 0);
    }
    
private:
    #define iterator vector<vector<long long>>::iterator
    void sort_count(iterator l, iterator r, vector<int>& count) {
        if (r - l <= 1) return;
        iterator m = l + (r - l) / 2;
        sort_count(l, m, count);
        sort_count(m, r, count);
        for (iterator i = l, j = m; i < m; i++) {
            while (j < r && (*i)[0] > 2 * (*j)[0]) j++;
            count[(*i)[1]] += j - m; // add the number of valid "j"s to the indices of *i
        }
        inplace_merge(l, m, r);
    }
};
