#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
	vector<vector<int> > rv;
        if(nums.size() < 4)
		return rv;

	sort(nums.begin(), nums.end());
	for(int i1 = nums.size() - 1; i1 >= 3;)
	{
		for(int i2 = i1 - 1; i2 >= 2;)
		{
			cout << nums[i2] << endl;
			int temp_tar = target - nums[i1] - nums[i2];
			cout << temp_tar << endl;
			for(int i3 = 0, i4 = i2 - 1; i3 < i4;)
			{
				int diff = nums[i3] + nums[i4] - temp_tar;
				cout << i3 << " - " << i4 << ": " << diff << endl;
				if(diff == 0)
				{
					vector<int> cand(1, nums[i3]);
					cand.push_back(nums[i4]);
					cand.push_back(nums[i2]);
					cand.push_back(nums[i1]);
					rv.push_back(cand);
				}

				if(diff >= 0)
					for(--i4; i4 > i3 && nums[i4] == nums[i4 + 1]; --i4) {}
				else
					for(++i3; i3 < i4 && nums[i3] == nums[i3 - 1]; ++i3) {}
			}
			for(--i2; i2 >= 2 && nums[i2] == nums[i2 + 1]; --i2) {}
		}

		for(--i1; i1 >= 3 && nums[i1] == nums[i1 + 1]; --i1) {}
	}

	return rv;
}

int main()
{
	vector<int> nums({1, 0, -1, 0, -2, 2});
	vector<vector<int> > r = fourSum(nums, 0);
	for(int i = 0; i < r.size(); ++i)
	{
		for(int j = 0; j < r[i].size(); ++j)
			cout << r[i][j] << ", ";
		cout << endl;
	}
	return 1;
}
