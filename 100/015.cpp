#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
  vector<vector<int> > results;
  
  if(nums.empty())
    return results;

  sort(nums.begin(), nums.end());

  for(int i = nums.size() - 1; i >= 2;) {
    int start = 0;
    int end = i - 1;
    int target = 0 - nums[i];

    while(start < end) {
      vector<int> result;
      if(nums[start] + nums[end] == target) {
	result.push_back(nums[start]);
	result.push_back(nums[end]);
	result.push_back(nums[i]);

	results.push_back(result);
      }

      if(nums[start] + nums[end] <= target)
	for(++start; start <= end && start == start - 1; ++start) {}

      if(nums[start] + nums[end] >= target)
	for(--end; start <= end && end == end + 1; --end) {}
    }

    for(--i; nums[i] != nums[i + 1]; --i) {}
  }

  return results;
}

int main()
{
  int array[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};

  vector<int> nums(array, array + sizeof(array) / sizeof(int));

  vector<vector<int> > results = threeSum(nums);
  cout << results.size() << endl;
  for(int i = 0; i < results.size(); ++i) {
    for(int j = 0; j < results[i].size(); ++j) {
      cout << results[i][j] << ", ";
    }
    cout << endl;
  }
  return 1;
}
