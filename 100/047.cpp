#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<vector<int> > >perms_alt(2, vector<vector<int> >());

	if(nums.empty())
		return perms_alt[0];

	perms_alt[0].push_back(vector<int>(1, nums[0]));
	if(nums.size() == 1)
		return perms_alt[0];

	sort(nums.begin(), nums.end());
	
	int size = nums.size();
	for(int i = 1; i < size; ++i)
	{
		int last = (i - 1) % 2;
		int current = i % 2;
		for(int j = perms_alt[last].size() - 1; j >= 0; --j)
		{
			vector<int> perm = perms_alt[last][j];
			perm.push_back(nums[i]);
			perms_alt[current].push_back(perm);
			for(int l = perm.size() - 1; l > 0; --l)
			{
				swap(perm[l], perm[l - 1]);
				if(perm[l] != perm[l - 1])
					perms_alt[current].push_back(perm);
			}
		}
		perms_alt[last].clear();
	}

	return perms_alt[(nums.size() - 1) % 2];
}

int main()
{
	int a[] = { 3,3,0,0,2,3,2 };
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	vector<vector<int> > r = permuteUnique(nums);
	for(int i = 0; i < r.size(); ++i)
	{
		for(int j = 0; j < r[i].size(); ++j)
			cout << r[i][j] << ", ";
		cout << endl;
	}
}
