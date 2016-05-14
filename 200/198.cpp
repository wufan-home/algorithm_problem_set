/*
  You are a professional robber planning to rob houses along a street. 
  Each house has a certain amount of money stashed, 
  the only constraint stopping you from robbing each of them 
  is that adjacent houses have security system connected 
  and it will automatically contact the police 
  if two adjacent houses were broken into on the same night.

  Given a list of non-negative integers representing the amount of money of each house, 
  determine the maximum amount of money you can rob tonight without alerting the police.
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
	if(nums.empty())
		return 0;

	if(nums.size() == 1)
		return nums[0];

	if(nums.size() == 2)
		return (nums[0] > nums[1] ? nums[0] : nums[1]);

	int size = nums.size();
	int sum_2_last = nums[0];
	int sum_last = (nums[0] > nums[1] ? nums[0] : nums[1]);
	for(int i = 2; i < size; ++i)
	{
		if(nums[i] == 0)
		{
			for(; i < size; ++i)
			{
				if(nums[i])
					break;
			}
			if(i == size)
				break;
		}
		int temp_sum = nums[i] + max(sum_2_last, sum_last);
		sum_2_last = max(sum_2_lat, sum_last);
		sum_last = temp_sum;
	}

	return max(sum_2_last, sum_last);
}

int main()
{
	return 1;
}
