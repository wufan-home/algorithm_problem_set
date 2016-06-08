// 39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void CombinationSumAux(vector<int>& candidates, int end, int target,
	vector<int>& result, vector<vector<int> >& results)
{
	if (target == 0)
	{
		vector<int> new_vec;
		for (int i = result.size() - 1; i >= 0; --i)
			new_vec.push_back(result[i]);
		results.push_back(new_vec);
		return;
	}

	for (int i = end; i >= 0; --i)
	{
		if (target < candidates[i])
			continue;

		result.push_back(candidates[i]);
		CombinationSumAux(candidates, i, target - candidates[i], result, results);
		result.erase(result.end() - 1);
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int> > results;

	if (candidates.empty())
		return results;

	sort(candidates.begin(), candidates.end());
	vector<int> numbers;
	int j = -1;
	for (int i = 0; i < candidates.size(); ++i)
	{
		if (candidates[i] > target)
			break;

		if (j == -1 || candidates[i] > numbers[j])
		{
			numbers.push_back(candidates[i]);
			++j;
		}
	}

	if (!numbers.empty())
	{
		vector<int> result;
		for (int end = numbers.size() - 1; end >= 0; --end)
		{
			result.push_back(candidates[end]);
			CombinationSumAux(numbers, end, target - candidates[end], result, results);
			result.erase(result.end() - 1);
		}
	}

	return results;
}

int main()
{
	int a[] = { 1, 2 };
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	vector<vector<int> > results = combinationSum(nums, 2);
	for (int i = 0; i < results.size(); ++i)
	{
		for (int j = 0; j < results[i].size(); ++j)
			cout << results[i][j] << ", ";

		cout << endl;
	}
    return 0;
}

