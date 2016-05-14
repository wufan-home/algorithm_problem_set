#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> rv;
	if(nums.empty())
		return rv;

	int exist = -1;
	int start = 0;
	int end = nums.size() - 1;
	for(; start <= end;)
	{
		int mid = start + (end - start + 1) / 2;
		if(nums[mid] == target)
		{
			exist = mid;
			break;
		}
		else if(mid == end)
		{
			cout << nums[start] << endl;
			exist = (nums[start] == target ? start : -1);
			break;
		}
		else if(nums[mid] < target)
			start = mid;
		else
			end = mid;
	}

	if(exist > -1)
	{
		for(start = exist - 1; start >= 0 && nums[start] == nums[exist]; --start) {}
		rv.push_back(start + 1);
		for(end = exist + 1; end < nums.size() && nums[end] == nums[exist]; ++end) {}
		rv.push_back(end - 1);
	}
	else
	{
		rv.push_back(-1);
		rv.push_back(-1);
	}

	return rv;
}

int main()
{
	vector<int> nums({1, 2, 3});
	vector<int> rv = searchRange(nums, 1);
	cout << rv[0] << ", " << rv[1] << endl;
	return 1;
}
