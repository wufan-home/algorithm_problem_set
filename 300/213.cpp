#include <vector>
#include <iostream>

using namespace std;

int robAux(vector<int>& nums, int start, int end)
{
	int sum2 = nums[start];
	int sum1 = (nums[start] > nums[start + 1] ? nums[start] : nums[start + 1]);
	for(int i = start + 2; i <= end; ++i)
	{
		int temp_sum = INT_MIN;
		if(nums[i] == 0)
		{
			for(; i <= end; ++i)
			{
				if(nums[i])
					break;
			}
			if(i > end)
				break;
			else
				temp_sum = nums[i] + max(sum1, sum2);
		}
		else
			temp_sum = nums[i] + sum2;
		sum2 = max(sum1, sum2);
		sum1 = temp_sum;
	}
	cout << sum1 << sum2 << endl;
	return max(sum1, sum2);
}

int rob(vector<int>& nums) {
        if(nums.size() <= 0)
		return 0;

	if(nums.size() == 1)
		return nums[0];

	if(nums.size() == 2)
		return (nums[0] > nums[1] ? nums[0] : nums[1]);

	cout << robAux(nums, 0, nums.size() - 2) << endl;
	cout << robAux(nums, 1, nums.size() - 1) << endl;
	return max(robAux(nums, 0, nums.size() - 2),
		   robAux(nums, 1, nums.size() - 1));
}

int main()
{
	int a[] = {1, 1, 1};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	cout << rob(nums) << endl;
	return 1;
}
