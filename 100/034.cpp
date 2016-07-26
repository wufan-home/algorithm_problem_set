/*
  Given a sorted array of integers, find the starting and ending position of a given target value.
  Your algorithm's runtime complexity must be in the order of O(log n).
  If the target is not found in the array, return [-1, -1].
  For example,
  Given [5, 7, 7, 8, 8, 10] and target value 8,
  return [3, 4].
*/

vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        vector<int>::iterator lb = lower_bound(nums.begin(), nums.end(), target);
        result.push_back(nums.empty() || lb == nums.end() || *lb != target ? -1 : lb - nums.begin());
        vector<int>::iterator ub = upper_bound(nums.begin(), nums.end(), target);
        result.push_back(nums.empty() || ub == nums.begin() || *(ub - 1) != target ? -1 : ub - nums.begin() - 1);
        return result;
}

int lower(const vector<int>& nums, int target)
{
	int l = 0;
	int r = nums.size() - 1;
	while(l < r)
	{
		int mid = l + (r - l) / 2;
		if(target <= nums[mid])
			r = mid;
		else
			l = mid + 1;
	}
	return nums.empty() || l == nums.size() || nums[l] != target ? -1 : l;
}

int upper(const vector<int>& nums, int target)
{
	int l = 0;
	int r = nums.size() - 1;
	while(l < r)
	{
		int mid = l + (r + 1 - l) / 2;
		if(nums[mid] <= target)
			l = mid;
		else
			r = mid - 1;
	}
	return nums.empty() || l == nums.size() || nums[l] != target ? -1 : l;
}

vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(lower(nums, target));
	result.push_back(upper(nums, target));
	return result;
}
