/*
  Rotate an array of n elements to the right by k steps.

  For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

  Note:
  Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
 */

#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<int>& nums, int k) {
        if(nums.size() < 2)
		return;

	k %= nums.size();
	if(k < 1)
		return;

	int iright = nums.size() - k;
	int ileft = iright - 1;
	for(int start = 0, end = ileft; start < end; ++start, --end)
		swap(nums[start], nums[end]);

	for(int start = iright, end = nums.size() - 1; start < end; ++start, --end)
		swap(nums[start], nums[end]);

	for(int start = 0, end = nums.size() - 1; start < end; ++start, --end)
		swap(nums[start], nums[end]);
}

void rotate1(vector<int>& nums, int k) {
	if(nums.size() < 2)
		return;

	k %= nums.size();
	if(k < 1)
		return;

	int iright = nums.size() - k;

	vector<int> right;
	for(int i = iright; i < nums.size(); ++i)
		right.push_back(nums[i]);

	vector<int> left;
	for(int i = 0; i < iright; ++i)
		left.push_back(nums[i]);
	
	for(int i = 0; i < k; ++i)
		nums[i] = right[i];

	for(int i = k; i < nums.size(); ++i)
		nums[i] = left[i - k];
}

int main()
{
	vector<int> nums;
	for(int i = 1; i <= 7; ++i)
		nums.push_back(i);

	for(int k = 0; k <= 8; ++k)
	{
		vector<int> nums1 = nums;
		rotate1(nums1, k);
		for(int i = 0; i < nums1.size(); ++i)
			cout << nums1[i] << ", ";
		cout << endl;
	}
	return 1;
}
