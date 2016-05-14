#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	if(nums.empty() || target < nums[0])
		return 0;

	if(target > nums[nums.size() - 1])
		return nums.size();

	int rv = INT_MIN;
	for(int start = 0, end = nums.size() - 1; start <= end;)
	{
		int mid = start + (end - start + 1) / 2;
		if(nums[mid] == target || mid == end)
		{
			rv = (nums[start] == target ? start : mid);
			break;
		}
		else if(nums[mid] > target)
			end = mid;
		else
			start = mid;
	}

	return rv;
}

/*
  In some cases, especially for the case to find the maximal lower bound,
  we do not need to care about the values that greater or equal to the 
  given value. Then, 
 */
int searchInsert2(vector<int>& nums, int target) {
	if(nums.empty() || target < nums[0])
		return 0;

	if(target > nums[nums.size() - 1])
		return nums.size();

	int rv = INT_MIN;
	for(int start = 0, end = nums.size() - 1; start <= end;)
	{
		int mid = start + (end - start + 1) / 2;
		if(nums[mid] == target || mid == end)
		{
			rv = (nums[start] == target ? start : mid);
			break;
		}
		else if(nums[mid] > target)
			end = mid;
		else
			start = mid;
	}

	return rv;
}
