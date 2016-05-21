#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void GetPerm(vector<int> nums, int cur, int size, vector<vector<int> >& perms)
{
  if(cur == size - 1)
    perms.push_back(nums);
  else
    {
      for(int i = cur; i < size; ++i)
	{
	  if (i != cur && nums[i] == nums[cur]) continue;
	  swap(nums[cur], nums[i]);
	  GetPerm(nums, cur + 1, size, perms);
	}
    }
}

vector<vector<int> > permuteUnique(vector<int> &nums) {
  // write your code here
  vector<vector<int> > perms;
  if(nums.empty())
    return perms;
  
  sort(nums.begin(), nums.end());
  GetPerm(nums, 0, nums.size(), perms);
  return perms;
}

int main()
{
	int a[] = { 3,3,0,0,2,3,2 };
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	vector<vector<int> > r = permuteUnique(nums);
	for(int i = 0; i < r.size(); ++i)
	{
		for(int j = 0; j < r[i].size(); ++j)
			cout << r[i][j] << ", ";
		cout << endl;
	}
}
