#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
		return 0;

	int max_len = 1;
	vector<int> max_len_list(nums.size(), 1);
	for(int i = 1; i < nums.size(); ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if(nums[j] < nums[i])
				max_len_list[i] = max(max_len_list[i], 1 + max_len_list[j]);
		}
		max_len = max(max_len, max_len_list[i]);
	}

	return max_len;
}

int main()
{
	return 1;
}
