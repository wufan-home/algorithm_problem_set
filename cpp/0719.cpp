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
    
    [38,33,57,65,13,2,86,75,4,56]
    26
    
    l , m  , r  : count
    0 , 42 , 85 : 28
    0 , 21 , 42 : 15
    22 , 32 , 42 : 24
    33 , 37 , 42 : 27
    33 , 35 , 37 : 25
    36 , 36 , 37 : 26
*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int l = 0;
        int r = nums.back() - nums.front() + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int count = 0;
            int j = 0;
            for (int i = 0; i < size; ++i) {
                for (; j < size && nums[j] - nums[i] <= mid; ++j) {}
                count += j - i - 1;
            }
            
            // The mid is a "guessed" difference - it may not be a real difference obtained by substracting two elements in the array.
            // There would be a "real" difference smaller than the "guessed" one while the count would be same.
            // It means that the difference not the least ???
            count >= k ? r = mid : l = mid + 1;
        }
        
        return l;
    }
};
