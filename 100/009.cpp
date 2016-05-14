#include <iostream>

using namespace std;

bool isPalindrome(int x) {
        if(x < 0)
		return false;

	int upper = 1000000000;
	while(upper > x)
		upper /= 10;

	int lower = 10;
	while(lower <= upper)
	{
		//cout << x / upper << " - " << x % lower << endl;
		if(x / upper != (x % lower))
			return false;

		x %= upper;
		x /= lower;
		upper /= 100;
		//cout << x << endl;
	}

	return true;
}

int main()
{
	cout << isPalindrome(12321) << endl;
	return 1;
}
