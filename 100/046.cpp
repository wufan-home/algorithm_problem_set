/*
   Given a collection of distinct numbers, return all possible permutations.

   For example,
   [1,2,3] have the following permutations:
   [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
*/

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > permute(vector<int>& nums) {
	vector<vector<vector<int> > > perms_alt(2, vector<vector<int> >());
	if(nums.empty())
		return perms_alt[0];

	vector<int> perm(1, nums[0]);
	perms_alt[0].push_back(perm);
	if(nums.size() == 1)
		return perms_alt[0];

	for(int i = 1; i < nums.size(); ++i)
	{
		int current = i % 2;
		int last = (i - 1) % 2;
		for(int j = perms_alt[last].size() - 1; j >= 0; --j)
		{
			vector<int> perm = perms_alt[last][j];
			perm.push_back(nums[i]);
			perms_alt[current].push_back(perm);
			for(int l = perm.size() - 1; l > 0; --l)
			{
				swap(perm[l], perm[l - 1]);
				perms_alt[current].push_back(perm);
			}
		}
		perms_alt[last].clear();
	}
	
	return perms_alt[(nums.size() - 1) % 2];
}

int main()
{
	int a[] = { 1, 2, 3};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	vector<vector<int> > r = permute(nums);
	for(int j = 0; j < r.size(); ++j)
		{
			for(int l = 0; l < r[j].size(); ++l)
				cout << r[j][l] << ", ";
			cout << endl;
		}
	return 1;
}
