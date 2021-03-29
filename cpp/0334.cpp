/*
   Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

	Formally the function should:

		Return true if there exists i, j, k
		such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 

	Your algorithm should run in O(n) time complexity and O(1) space complexity.

	Examples:
	Given [1, 2, 3, 4, 5],
	return true.

	Given [5, 4, 3, 2, 1],
	return false. 
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > second)
                return true;
            
            if(nums[i] < first)
                first = nums[i];
            else if(nums[i] > first && nums[i] < second)
                second = nums[i];
        }
        
        return false;
    }
};
