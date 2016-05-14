#include <iostream>
#include <vector>

using namespace std;

int Search(const vector<int>& nums, int target)
{
  if(nums.empty())
    return -1;
  
  if(nums.size() == 1)
    return (nums[0] == target ? 0 : -1);


  int start = 0;
  int end = nums.size() - 1;
  while(start <= end) {
    //cout << "Start = " << start << ", end = " << end;
    if(start == end)
      return nums[start] == target ? start : -1;

    if(start == end - 1) {
      if(target == nums[start])
	return start;
      else if(target == nums[end])
	return end;
      else
	return -1;
    }

    int mid = (start + end + 1) / 2;
    //cout << ", mid = " << mid << endl;
    if(target == nums[mid])
      return mid;
    else if(nums[start] < nums[mid]) {
      //right side
      if(nums[start] <= target && target < nums[mid])
	end = mid - 1;
      else
	start = mid + 1;
    } else if(nums[start] > nums[mid]) {
      //left side
      if(nums[mid] < target && target <= nums[end])
	start = mid + 1;
      else
	end = mid - 1;
    }
  }

  return -1;
}

int main()
{
  vector<int> nums1;
  for(int i = 7; i < 8; ++i)
    nums1.push_back(i);
  for(int i = 0; i < 7; ++i)
    nums1.push_back(i);

  for(int i = 0; i < nums1.size(); ++i)
    cout << nums1[i] << ", ";
  cout << endl;

  for(int i = -1; i <= 11; ++i)
    cout << "target = " << i << ": " << Search(nums1, i) << endl;

  return 1;
}
