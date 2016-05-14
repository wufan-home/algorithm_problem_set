#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
	long long rv = 0;
	bool neg = (x < 0);
	long long abx = (neg ? -1 : 1) * static_cast<long long>(x);
	for(; abx; abx /= 10)
	{
		rv = rv * 10 + abx % 10;
		if((neg && rv <= INT_MIN) || (rv >= INT_MAX))
			return 0;
	}
	return (neg ? -1 : 1) * static_cast<int>(rv);
}
