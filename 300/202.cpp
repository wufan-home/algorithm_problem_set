#include <iostream>

using namespace std;

bool isHappy(int n) {
        while(n >= 7)
	{
		int sum = 0;
		for(; n ; n /= 10)
			sum += (n % 10) * (n % 10);
		n = sum;
	}

	return n == 1;
}

int main()
{
	return 1;
}
