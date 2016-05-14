/*
   Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

   Do not allocate extra space for another array, you must do this in place with constant memory.

   For example,
   Given input array nums = [1,1,2],

   Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

   Subscribe to see which companies asked this question
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if(nums.size() < 1)
		return 1;

	int read = 1;
	int write = 0;
	while(read < nums.size())
	{
		if(nums[read] == nums[write])
			for(++read; read < nums.size() && nums[read] == nums[write]; ++ read) {}
		//cout << read << ", " << write << endl;
		swap(nums[read++], nums[++write]);
		for(int i = 0; i < nums.size(); ++i)
			cout << nums[i] << ", ";
		cout << endl;
	}
	return write + 1;
}

int main()
{
	vector<int> nums({-3,-3,-2,-1,-1,0,0,0,0,0});
	cout << removeDuplicates(nums) << endl;
	return 1;
}
