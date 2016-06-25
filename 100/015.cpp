/*
  Given an array S of n integers, are there elements a, b, c in S 
  such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
  Note: The solution set must not contain duplicate triplets.
  For example, given array S = [-1, 0, 1, 2, -1, -4],
  A solution set is:
  [
    [-1, 0, 1],
    [-1, -1, 2]
  ]
*/

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
