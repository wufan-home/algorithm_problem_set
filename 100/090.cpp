#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Generate(vector<int>& nums, int start,
	      vector<int>& subset, vector<vector<int> >& rv)
{
	for(int i = start; i < nums.size();)
	{
		int cur = i;
		vector<int> cur_v = subset;
		for(++i; i < nums.size() && nums[i] == nums[cur]; ++i) {}
		for(int j = cur; j < i; ++j)
		{
			subset.push_back(nums[j]);
			rv.push_back(subset);
			Generate(nums, i, subset, rv);
		}
		subset = cur_v;
	}
}

vector<vector<int> > subsetsWithDup(vector<int>& nums)
{
	vector<vector<int> > rv;
	if(nums.empty())
		return rv;

	sort(nums.begin(), nums.end());
	vector<int> subset;
	Generate(nums, 0, subset, rv);
	return rv;
}

int main()
{
	vector<int> nums({-1, 0, 2, 4});
	vector<vector<int> > rv = subsetsWithDup(nums);
	for(int i = 0; i < rv.size(); ++i)
	{
		for(int j = 0; j < rv[i].size(); ++j)
			cout << rv[i][j] << ", ";
		cout << endl;
	}
	return 1;
}
