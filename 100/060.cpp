#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getPermutation(int n, int k)
{
	string ostr("");
	for(int i = 1; i <= n; ++i)
		ostr.push_back(i + '0');
	string result("");

	long long total = 1;
	for(int i = 1; i < n - 1; ++i)
		total *= i + 1;

	for(int i = 1; ; ++i)
	{
		int rm_index = (k % total ? k / total : k / total - 1);
		if(rm_index < 0)
			rm_index = 0;
		result.push_back(ostr[rm_index]);
		ostr.erase(ostr.begin() + rm_index);
		if(ostr.empty())
			break;
		k = (k % total == 0 ? total : k % total);
		total /= n - i;
	}
	
	return result;
}

int main()
{
	for(int i = 1; i <= 6; ++i)
		cout << getPermutation(3, i) << endl;
	return 1;
}
