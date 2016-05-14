#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int integerBreak(int n) {
	//cout << "n = " << n << endl;
        if(n <= 2)
		return 1;

	if(n == 3)
		return 2;

	long long rv = INT_MIN;
	int bound = n / 2;
	//cout << bound << endl;
	for(int i = bound; n / i <= bound; --i)
	{
		int quo = n / i;
		int diff = n - quo * i;
		long long prod = ((long long)pow(quo + 1, diff)) * ((long long)pow(quo, i - diff));
		//cout << quo << ", " << diff << ", " << prod << endl;
		rv = max(rv, prod);
	}
	return rv;
}

int main()
{
	for(int i = 1; i <= 10; ++i)
		cout << integerBreak(i) << endl;
	return 1;
}
