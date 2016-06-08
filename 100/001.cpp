/*
  Given an array of integers, 
  return indices of the two numbers such that they add up to a specific target.
  You may assume that each input would have exactly one solution.
  Example:
  Given nums = [2, 7, 11, 15], target = 9,
  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
  UPDATE (2016/2/13):
  The return format had been changed to zero-based indices. 
  Please read the above updated description carefully.

  Solution:
  1. Two-pointers:
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

static bool Compare(const pair<int, int> l, const pair<int, int> r)
{
	return l.first <= r.first;
}

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> r;
	vector<pair<int, int> > nums1;
	for(int i = 0; i < nums.size(); ++i)
		nums1.push_back(make_pair(nums[i], i));

	sort(nums1.begin(), nums1.end(), Compare);

	for(int start = 0, end = nums1.size() - 1; start < end;)
	{
		if(nums1[start].first + nums1[end].first == target)
		{
			r.push_back(nums1[start].second);
			r.push_back(nums1[end].second);
			sort(r.begin(), r.end());
			break;
		}
		else if(nums1[start].first + nums1[end].first > target)
			for(--end; end > start && nums1[end].first == nums1[end + 1].first; --end) {}
		else
			for(++start; start < end && nums1[start].first == nums1[start - 1].first; ++start) {}
	}

	return r;
}

vector<int> twoSum1(vector<int>& nums, int target)
{
	vector<int> rv;
	if(nums.size() < 2)
		return rv;

	if(nums.size() == 2)
	{
		rv.push_back(0);
		rv.push_back(1);
		return rv;
	}

	unordered_map<int, int> hash_map;
	for(int i = 0; i < nums.size(); ++i)
	{
		unordered_map<int, int>::iterator it = hash_map.find(target - nums[i]);
		if(it != hash_map.end())
		{
			rv.push_back(i);
			rv.push_back(it->second);
			sort(rv.begin(), rv.end());
			break;
		}

		hash_map[nums[i]] = i;
	}

	return rv;
}
