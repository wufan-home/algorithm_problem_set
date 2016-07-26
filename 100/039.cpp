/*
	 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:

[
  [7],
  [2, 2, 3]
]

*/

void DoCombination(vector<int>& candidates, int target, int index, vector<int>& numbers, vector<vector<int> >& results)
{
	if(target == 0)
		results.push_back(numbers);
	else if(candidates[0] <= target)
	{
		for(int i = index; i >= 0; --i)
		{
			if(candidates[i] <= target)
			{
				numbers.push_back(candidates[i]);
				DoCombination(candidates, target - candidates[i], i, numbers, results);
				numbers.pop_back();
			}
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int> > results;
	if (candidates.empty())
		return results;

	sort(candidates.begin(), candidates.end());
	vector<int> numbers;
	DoCombination(candidates, target, candidates.size() - 1, numbers, results);
	return results;
}
