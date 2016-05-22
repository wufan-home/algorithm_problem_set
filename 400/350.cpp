/*
  Given two arrays, write a function to compute their intersection.

  Example:
  Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

  Note:
  Each element in the result should appear as many times as it shows in both arrays.
  The result can be in any order.
  Follow up:
  What if the given array is already sorted? How would you optimize your algorithm?
  What if nums1's size is small compared to num2's size? Which algorithm is better?
  What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

  Solution:
  1. We always assume that the length of the nums2 is smaller than nums1. 
     Otherwise, we swap nums1 and nums2 by calling intersect(nums2, nums1).
     Use a hash table to record the times of each element.
     For each element of the second array, add it to the result if it is found in the hash table and the time is greater than 0.
  2. We do not need to use the hash table. Please the refer the last questions.
  3. Change the calling order.
  4. The hash table maybe much smaller than the original array, and then it can be cached in the main memory.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespaice std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  if(nums1.empty() || nums2.empty())
    return vector<int>();

  if(nums1.size() < nums2.size())
    return intersect(nums2, nums1);
  
  unordered_map<int, int> num_count1;
  for(int i = 0; i < nums1.size(); ++i)
  {
    if(num_count1.find(nums1[i]) == num_count1.end())
      num_count1[nums1[i]] = 1;
    else
      ++num_count1[nums1[i]];
  }

  vector<int> result;
  for(int i = 0; i < nums2.size(); ++i)
  {
    if(num_count1.find(nums2[i]) != num_count1.end() && num_count1[nums2[i]] > 0)
    {
      --num_count1[nums[i]];
      result.push_back(nums2[i]);
    }
  }

  return result;
}
