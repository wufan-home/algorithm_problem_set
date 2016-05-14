// 40.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void CombinationSum2Aux(vector<int>& candidates, int end, int target,
	vector<int>& result, vector<vector<int> >& results)
{
	if (target == 0)
	{
		vector<int> new_vec;
		for (int i = result.size() - 1; i >= 0; --i)
			new_vec.push_back(result[i]);
		if (find(results.begin(), results.end(), new_vec) == results.end())
			results.push_back(new_vec);
		return;
	}

	for (int i = end - 1; i >= 0; --i)
	{
		if (target < candidates[i])
			continue;

		result.push_back(candidates[i]);
		CombinationSum2Aux(candidates, i, target - candidates[i], result, results);
		result.erase(result.end() - 1);
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int> > results;

	if (candidates.empty())
		return results;

	sort(candidates.begin(), candidates.end());

	for (int end = candidates.size() - 1; end >= 0;)
	{
		if (target < candidates[end])
		{
			--end;
			continue;
		}

		vector<int> result(1, candidates[end]);
		CombinationSum2Aux(candidates, end, target - candidates[end], result, results);

		for (--end; end >= 0; --end)
		{
			if (candidates[end] != candidates[end + 1])
				break;
		}
	}

	return results;
}

int main()
{
	//int a[] = { 23, 32, 22, 19, 29, 15, 11, 26, 28, 20, 34, 5, 34, 7, 28, 33, 30, 30, 16, 33, 8, 15, 28, 26, 17, 10, 25, 12, 6, 17, 30, 16, 6, 10, 23, 22, 20, 29, 14, 5, 6, 5, 5, 6, 29, 20, 34, 24, 16, 7, 22, 11, 17, 7, 33, 21, 13, 15, 29, 6, 19, 16, 10, 21, 21, 28, 8, 6 };
	int a[] = { 10,1,2,7,6,1,5 };
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	vector<vector<int> > results = combinationSum2(nums, 8);
	for (int i = 0; i < results.size(); ++i)
	{
		for (int j = 0; j < results[i].size(); ++j)
		{
			cout << results[i][j] << ", ";
		}
		cout << endl;
	}

    return 0;
}

