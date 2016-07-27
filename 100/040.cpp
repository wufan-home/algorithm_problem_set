/*
  Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
  Each number in C may only be used once in the combination.
  Note:
  All numbers (including target) will be positive integers.
  The solution set must not contain duplicate combinations.
  For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
  A solution set is: 
  [
    [1, 7],
    [1, 2, 5],
    [2, 6],
    [1, 1, 6]
  ]
*/

void DoCombinationSum2(const vector<int>& candidates,
		       int start, int target,
		       vector<int>& nums,
		       vector<vector<int> >& results)
{
	if(target < 0)
		return;
	else if(target == 0)
		results.push_back(nums);
	else if(candidates[0] <= target)
	{
		int backup = target;
		for(; start >= 0 && candidates[start] > target; --start) {}
		while(start >= 0)
		{
			int next = start - 1;
			for(; next >= 0 && candidates[next] == candidates[next + 1]; --next) {}
			for(int i = start; i > next; --i)
			{
				target -= candidates[i];
				nums.push_back(candidates[i]);
				DoCombinationSum2(candidates, next, target, nums, results);
			}
			for(int i = start; i > next; --i, nums.pop_back()) {}
			target = backup;
			start = next;
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int> > results;
	if (candidates.empty())
		return results;

	sort(candidates.begin(), candidates.end());
	vector<int> nums;
	//cout << target << endl;
	DoCombinationSum2(candidates, candidates.size() - 1, target, nums, results);
	return results;
}
