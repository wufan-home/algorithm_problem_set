/*
  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
  Return the sum of the three integers. You may assume that each input would have exactly one solution.
  For example, given array S = {-1 2 1 -4}, and target = 1.
  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

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
			else if(val > t1)
				for(--e; e > s && nums[e] == nums[e + 1]; --e) {}
			else
				for(++s; s < e && nums[s] == nums[s - 1]; ++s) {}
		}
		for(--i; i >= 2 && nums[i] == nums[i + 1]; --i) {}
	}

	return rv;
}


