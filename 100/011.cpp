#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
        if(height.size() < 2)
		return 0;

	int max_area = 0;
	for(int s = 0, e = height.size() - 1; s < e;)
	{
		int area = (e - s) * min(height[s], height[e]);
		max_area = max(area, max_area);
		height[s] <= height[e] ? ++s : --e;
	}

	return max_area;
}

int main()
{
	vector<int> h(1, 2);
	h.push_back(1);
	cout << maxArea(h) << endl;
	return 1;
}
