/*
  Given a collection of integers that might contain duplicates, nums, return all possible subsets.
  Note: The solution set must not contain duplicate subsets.
  For example,
  If nums = [1,2,2], a solution is:
  [
    [2],
    [1],
    [1,2,2],
    [2,2],
    [1,2],
    []
  ]
*/

void Generate(vector<int>& nums, int start,
	      vector<int>& subset, vector<vector<int> >& result)
{
	for(int i = start; i < nums.size();)
	{
		int cur = i;
		vector<int> cur_v = subset;
		for(++i; i < nums.size() && nums[i] == nums[cur]; ++i) {}
		for(int j = cur; j < i; ++j)
		{
			subset.push_back(nums[j]);
			result.push_back(subset);
			Generate(nums, i, subset, rv);
		}
		subset = cur_v;
	}
}

vector<vector<int> > subsetsWithDup(vector<int>& nums)
{
	vector<vector<int> > result;
	if(nums.empty())
		return result;

	sort(nums.begin(), nums.end());
	vector<int> subset;
	Generate(nums, 0, subset, result);
	return result;
}
