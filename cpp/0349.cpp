/*
  Given two arrays, write a function to compute their intersection.

  Example:
  Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

  Note:
  Each element in the result must be unique.
  The result can be in any order.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MoveIndex(vector<int>& nums, int& index)
{
  for(++index; index < nums.size() && nums[index] == nums[index - 1]; ++index) {}
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  if(nums1.empty() || nums2.empty())
    return vector<int>();

  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  vector<int> result;
  for(int i1 = 0, i2 = 0; i1 < nums1.size() && i2 < nums2.size();)
  {
    if(nums1[i1] == nums2[i2])
    {
      result.push_back(nums1[i1]);
      MoveIndex(nums1, i1);
      MoveIndex(nums2, i2);
    }
    else if(nums1[i1] < nums2[i2])
      MoveIndex(nums1, i1);
    else
      MoveIndex(nums2, i2);
  }

  return result;
}

vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
  if(nums1.empty() || nums2.empty())
    return vector<int>();

  unordered_set<int> hash;
  for(int i = 0; i < nums1.size(); ++i)
  {
    if(hash.find(nums1[i]) == hash.end())
      hash.insert(nums1[i]);
  }

  vector<int> result;
  unordered_set<int> visited;
  for(int i = 0; i < nums2.size(); ++i)
  {
    if(hash.find(nums2[i]) != hash.end() && visited.find(nums2[i]) == visited.end())
    {
      result.push_back(nums2[i]);
      visited.insert(nums2[i]);
    }
  }

  return result;
}
