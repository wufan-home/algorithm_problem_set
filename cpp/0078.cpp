#include <vector>
#include <iostream>

using namespace std;

void Generate(vector<int>& nums, int start,
	      vector<int>& subset, vector<vector<int> >& rv)
{
	for(int i = start; i < nums.size(); ++i)
	{
		subset.push_back(nums[i]);
		rv.push_back(subset);
		Generate(nums, i + 1, subset, rv);
		subset.pop_back();
	}
}

vector<vector<int> > subsets(vector<int>& nums)
{
	vector<vector<int> > rv;
	vector<int> subset;
	Generate(nums, 0, subset, rv);
	return rv;
}

int main()
{
	vector<int> nums({1, 2, 3});
	vector<vector<int> > rv = subsets(nums);
	for(int i = 0; i < rv.size(); ++i)
	{
		cout << "[ ";
		cout << rv[i][0];
		for(int j = 1; j < rv[i].size(); ++j)
			cout << ", " << rv[i][j];
		cout << " ]" << endl;
	}
	return 1;
}
