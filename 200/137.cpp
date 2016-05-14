// 137.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int result = 0;
	for (int i = 31; i >= 0; --i) {
		int digit = 0;
		for (int j = 0; j < nums.size(); ++j)
			digit += (nums[j] >> i) & 1;

		digit %= 3;
		result += digit << i;
	}

	return result;
}

int main()
{
	int a[] = {-2, -2, 1, 1, -3, 1, -3, -3, -4, -2};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	cout << singleNumber(nums) << endl;
    return 0;
}

