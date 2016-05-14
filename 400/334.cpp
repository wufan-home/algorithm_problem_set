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

#include <vector>
#include <iostream>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
        if(nums.size() <= 2)
		return false;

	int first = nums[0];
	int second = INT_MAX;
	for(int i = 1; i < nums.size(); ++i)
	{
		if(nums[i] > second)
			return true;
		else if(nums[i] < second && nums[i] > first)
			second = nums[i];
		else if(nums[i] < first)
			first = nums[i];
	}

	return false;
}

int main()
{
	int a[] = {1,2,-1,3};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	cout << increasingTriplet(nums) << endl;
	return 1;
}
