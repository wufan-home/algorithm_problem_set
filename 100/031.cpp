#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
  if(nums.empty())
    return;

  int last = nums.size() - 1;
  int start = last;
  for(; start > 0; --start) {
    if(nums[start] > nums[start - 1])
      break;
  }

  if(start != 0) {
    for(int i = last; i >= start; --i) {
      if((i == last && nums[i] > nums[start - 1])
	 || (nums[i] > nums[start - 1] && nums[i + 1] < nums[start - 1])) {
	int temp = nums[i];
	nums[i] = nums[start - 1];
	nums[start - 1] = temp;
	break;
      }
    }
  }

  for(; start <= last; ++start, --last) {
    int temp = nums[start];
    nums[start] = nums[last];
    nums[last] = temp;
  }
}

int main()
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  for(int i = 0; i < 24; ++i) {
    nextPermutation(nums);
    for(int j = 0; j < 4; ++j)
      cout << nums[j] << ", ";
    cout << endl;
  }
  return 1;
}
