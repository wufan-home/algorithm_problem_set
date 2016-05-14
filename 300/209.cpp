#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
		return 0;

	int min_len = nums.size() + 1;
	int sum = 0;
	for(int tail = 0, head = 0; head < nums.size(); ++head)
	{
		sum += nums[head];
		if(sum >= s)
		{
			for(; tail <= head && sum >= s; ++tail)
			{
				if(head - tail + 1 < min_len)
					min_len = head - tail + 1;
				sum -= nums[tail];
			}
		}
	}

	return min_len > nums.size() ? 0 : min_len;
}

int main()
{
	return 1;
}
