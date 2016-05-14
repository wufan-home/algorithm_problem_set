#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
		return INT_MIN;

	int rv = 0;
	int min_diff = INT_MAX;
	sort(nums.begin(), nums.end());
	for(int i = nums.size() - 1; i >= 2; --i)
	{
		for(int s = 0, e = i - 1; s < e;)
		{
			int val = nums[s] + nums[e] + nums[i];
			if(abs(target - val) < min_diff)
			{
				rv = val;
				max_diff = abs(target - val);
			}
			else if(val > target)
				for(--e; e > s && nums[e] == nums[e + 1]; --e) {}
			else
				for(++s; s < e && nums[s] == nums[s - 1]; ++s) {}
		}
	}

	return rv;
}

int main()
{
	return 1;
}

