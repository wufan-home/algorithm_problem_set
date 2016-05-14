#include <iostream>
#include <vector>
#include <set>

using namespace std;

int longestConsecutive(vector<int>& nums)
{
	set<int> hash_nums;
	int size = nums.size();
	for(int i = 0; i < size; ++i)
		hash_nums.insert(hash_nums.begin(), nums[i]);

	int max_len = 0;
	for(set<int>::iterator it = hash_nums.begin(); it != hash_nums.end(); ++it)
	{
		if(hash_nums.find(*it - 1) == hash_nums.end())
		{
			int len = 0;
			for(int i = *it; ; ++i)
			{
				if(hash_nums.find(i) == hash_nums.end())
					break;
				else
					++len;
			}
			cout << len << endl;
			if(len > max_len)
				max_len = len;
		}
	}

	return max_len;
}

int main()
{
	int a[] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
	vector<int> a1(a, a + sizeof(a) / sizeof(int));
	cout << longestConsecutive(a1) << endl;
	return 1;
}
