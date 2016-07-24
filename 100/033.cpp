/*
  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  You are given a target value to search. If found in the array return its index, otherwise return -1.
  You may assume no duplicate exists in the array.

  Solution: Binary search. We first distinguish which part is a rotate array.
  For the sorted part, use the usual binary search.
  For the rotated part, use the recursive part.
*/

int Search(const vector<int>& nums, int target)
{
	int l = 0;
	int r = nums.size() - 1;
	while(l < r)
	{
		int mid = l + (r + 1 - l) / 2;
		if(nums[mid] <= nums[r])
		{
			if(nums[mid] <= target && target <= nums[r])
				l = mid;
			else
				r = mid - 1;
		}
		else
		{
			if(nums[l] <= target && target <= nums[mid])
				r = mid;
			else
				l = mid + 1;
		}
	}
	return nums.empty() || nums[l] != target ? -1 : l;
}
