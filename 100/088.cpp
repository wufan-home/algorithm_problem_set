// 88.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (n == 0 && m == 0)
		return;

	int n1 = m - 1;
	int n2 = n - 1;
	for (int i = m + n - 1; i >= 0; --i)
	{
		if (n2 < 0)
			break;

		if (n1 < 0)
			nums1[i] = nums2[n2--];

		nums1[i] = (nums2[n2] > nums1[n1] ? nums2[n2--] : nums1[n1--]);
	}
}

int main()
{
	vector<int> nums1(1, 0);
	vector<int> nums2(1, 1);
	merge(nums1, 0, nums2, 1);
	for (int i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << endl;

    return 0;
}

