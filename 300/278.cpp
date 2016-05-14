// 278.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool isBadVersion(int num)
{
	if (num >= 2)
		return true;

	return false;
}

int firstBadVersion(int n) {
	if (n == 1)
		return 1;

	long long start = 1;
	long long end = n;
	while (start < end) {
		if (start == end - 1)
			return (isBadVersion(start) ? start : end);

		long long mid = (start + end) / 2;
		if (isBadVersion(static_cast<int>(mid)))
			end = mid - 1;
		else
			start = mid + 1;
	}

	return start;
}

int main()
{
	cout << firstBadVersion(3) << endl;
    return 0;
}

