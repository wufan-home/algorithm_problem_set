/*
  Given an array and a value, remove all instances of that value in place and return the new length.

  Do not allocate extra space for another array, you must do this in place with constant memory.

  The order of elements can be changed. It doesn't matter what you leave beyond the new length.

  Example:
  Given input array nums = [3,2,2,3], val = 3

  Your function should return length = 2, with the first two elements of nums being 2.
*/

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int read = 0, write = nums.size() - 1;
	while(read < write)
	{
		if(nums[read] == val)
			swap(nums[read], nums[write--]);
		else
			++read;
	}

	return (nums.empty() ||
		(read == 0 && nums[read] == val) ?
		0 : (nums[read] == val ? read : read + 1));
}

int main()
{
	vector<int> nums({4, 5});
	cout << removeElement(nums, 5) << endl;
	return 1;
}
