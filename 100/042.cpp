// 42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
	if (height.size() < 3)
		return 0;

	stack<int> barriers;
	int start = 0;
	for (; start < height.size() - 1; ++start)
	{
		if (height[start] > height[start + 1])
			break;
	}

	if (start == height.size() - 1)
		return 0;

	barriers.push(start);
	for (int i = start + 1; i < height.size(); ++i)
	{
		if (height[i] > height[i - 1])
		{
			if (barriers.size() == 1 || height[i] <= height[barriers.top()])
				barriers.push(i);
			else
			{
				while (barriers.size() > 1)
				{
					barriers.pop();
					if (barriers.size() == 1 || height[i] <= height[barriers.top()])
						break;

					int temp = barriers.top();
					barriers.pop();
					if (height[temp] > height[barriers.top()])
					{
						barriers.push(temp);
						break;
					}
				}
				barriers.push(i);
			}
		}
		else
			barriers.push(i);
	}

	int max_volume = 0;
	while (barriers.size() > 1)
	{
		int right_index = barriers.top();
		int right = height[right_index];
		barriers.pop();
		int left_index = barriers.top();
		int left = height[left_index];

		int local_h = min(left, right);
		for (int i = right_index - 1; i > left_index; --i)
		{
			max_volume += (local_h - height[i]);
		}
	}

	return max_volume;
}

int main()
{
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << trap(vector<int>(a, a + sizeof(a) / sizeof(int))) << endl;
    return 0;
}

