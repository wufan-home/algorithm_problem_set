#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const string& l, const string& r)
{
	static int count = 0;
	int len = (l.size() >= r.size() ? l.size() : r.size());
	cout << ++count << endl;
	cout << l << ", " << r << endl;
	for(int i = 0; i < len; ++i)
	{
		if(i < l.size() && i < r.size())
		{
			if(l[i] != r[i])
				return l[i] < r[i];
		}
		else if(i >= l.size() && i < r.size())
		{
			if(l[l.size() - 1] != r[i])
				return l[l.size() - 1] < r[i];
		}
		else if(i >= r.size() && i < l.size())
		{
			if(l[i] != r[r.size() - 1])
				return l[i] < r[r.size() - 1];
		}
	}
	cout << count << endl;
	return true;
}

string to_string(int num)
{
	if(num == 0)
		return "0";

	string r("");
	while(num != 0)
	{
		int digit = num % 10;
		num /= 10;
		r.insert(r.begin(), digit + '0');
	}
	return r;
}

string largestNumber(vector<int>& nums) {
        if(nums.empty())
		return "";

	string r("");

	int size = nums.size();
	vector<string> snums;
	for(int i = 0; i < size; ++i)
		snums.push_back(to_string(nums[i]));
	for(int i = 0; i < snums.size(); ++i)
		cout << snums[i] << " - ";
	cout << endl;
	
	sort(snums.begin(), snums.end(), Compare);
	for(int i = 0; i < snums.size(); ++i)
		cout << snums[i] << " - ";
		cout << endl;

	for(int i = snums.size() - 1; i >= 0; --i)
		r.append(snums[i]);

	return r;
}

int main()
{
	int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	cout << largestNumber(nums) << endl;
	return 1;
}
