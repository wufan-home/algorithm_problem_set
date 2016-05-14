#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
		return 0;

	int end = 1;
	for(int i = 2; i < nums.size(); ++i)
	{
		if(nums[end] > nums[end - 1] || nums[i] > nums[end])
			nums[++end] = nums[i];
	}

	return end + 1;
}

int main()
{
	int a[] = {1, 2};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	cout << removeDuplicates(nums) << endl;
	return 1;
}
