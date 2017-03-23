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
  1. Two-pointers method: Construct a new array, each element of which consist of value and its index.
     Sort this array by the values: Need to override the internal-defined compare function. 
     Use two pointers search from two end-points of the new array: move the end pointer to the left,
     if the sum of two values are smaller than the target; move the left pointer to the right, 
     if the sum is larger than the target.
     Return the array of two indices if the sum is equal to the target.
     Time complexity: O(nlogn) - The sort part costs the most part of the time.
     Space complexity: O(n).

  2. Hash-set method: Use a hash set to store indices of elements.
     Starting from the left side of the array, 
     check if the substraction of target and the current element.
     If so, return the stored index and the current index.
     If not, store the index of the current element to the hash set.
     Time complexity: O(n) - The checking of existence of the difference is O(1).
     Space complexity: O(n).
*/

#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

static bool compare(const pair<int, int>& l, const pair<int, int>& r)
    {
        return l.first <= r.first;
    }
    
    static void fillIndexToResult(vector<int>& result, int i1, int i2)
    {
        result.push_back(min(i1, i2));
        result.push_back(max(i1, i2));
    }
    
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        
        vector<pair<int, int>> value_to_index_list;
        for(int i = 0; i < nums.size(); ++i)
            value_to_index_list.push_back(make_pair(nums[i], i));
            
        sort(value_to_index_list.begin(), value_to_index_list.end(), compare);
        
        for(int li = 0, ri = value_to_index_list.size() - 1; li < ri;)
        {
            const int sum = value_to_index_list[li].first + value_to_index_list[ri].first;
            if(sum == target)
            {
                fillIndexToResult(result, value_to_index_list[li].second, value_to_index_list[ri].second);
                break;
            }
            else if(sum < target)
                for(++li; li < ri && value_to_index_list[li].first == value_to_index_list[li - 1].first; ++li) {}
            else
                for(--ri; li < ri && value_to_index_list[ri].first == value_to_index_list[ri + 1].first; --ri) {}
        }
        
        return result;
    }

vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> value_to_index;
        for(int i = 0; i < nums.size(); ++i)
        {
            const unordered_map<int, int>::iterator index_of_diff_it 
                = value_to_index.find(target - nums[i]);
            if(index_of_diff_it != value_to_index.end())
            {
                const int cached_index = index_of_diff_it->second;
                result.push_back(min(i, cached_index));
                result.push_back(max(i, cached_index));
                break;
            }
            
            value_to_index[nums[i]] = i;
        }
        
        return result;
    }
