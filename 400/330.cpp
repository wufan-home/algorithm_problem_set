#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int patching(const vector<int>& nums, const int n)
{
  int num = 0;

  //sort(nums.begin(), nums.end());

  int index = 0;
  long long temp = n;
  long long max_reach = 0;
    
  while(1) {
    cout << max_reach << endl;
    if(index < nums.size()
       && (max_reach >= nums[index] || nums[index] == 1)) {
      max_reach += nums[index++];
      if(max_reach >= n)
	break;
    } else {
      ++num;
      max_reach = 2 * max_reach + 1;
    }
  }

  return num;
}

int main()
{
  int num[] = {1, 2, 31, 33};
  vector<int> test1(num, num + sizeof(num) / sizeof(int));
  cout << patching(test1, 2147483647) << endl;
  return 1;
}
