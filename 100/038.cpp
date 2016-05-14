#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
	string rv = "1";
        for(int i = 2; i <= n; ++i)
	{
		string cand = "";
		for(int sample = 0; sample < rv.size();)
		{
			int test = sample;
			for(; sample < rv.size() && rv[test] == rv[sample]; ++test) {}

			cand.push_back(test - sample + '0');
			cand.push_back(rv[sample]);
			sample = test;
		}
		rv = cand;
	}

	return rv;
}

int main()
{
	for(int i = 1; i < 10; ++i)
		cout << countAndSay(i) << endl;

	return 1;
}
