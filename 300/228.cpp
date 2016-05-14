/*
   Given a sorted integer array without duplicates, return the summary of its ranges.

   For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
        vector<string> rv;
	if(nums.empty())
		return rv;

	for(int i = 0; i < nums.size();)
	{
		string interval("");
		if(i == nums.size() - 1 || nums[i] != nums[i + 1] - 1)
			interval = to_string(nums[i++]);
		else
		{
			int start = nums[i];
			for(++i; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i) {}
			interval = to_string(start) + "->" + to_string(nums[i - 1]);
		}
		rv.push_back(interval);
	}

	return rv;
}

int main()
{
	vector<int> nums({0,1,2,4,5,7});
	vector<string> rv = summaryRanges(nums);
	for(int i = 0; i < rv.size(); ++i)
	{
		cout << rv[i] << endl;
	}
	return 1;
}
