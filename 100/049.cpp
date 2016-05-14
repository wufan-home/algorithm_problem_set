#include <iostream>
#include <cmath>

using namespace std;

double MyPowAux(double x, long long n)
{
	if(n == 1)
		return x;
	else
		return MyPowAux(x * x, n / 2) * (n % 2? x : 1);
}


double myPow(double x, int n) {
	if(x == 0 || x == 1 || n == 1)
		return x;
	
        if(n == 0)
		return 1;

	int index = (n < 0 ? -1 * n : n);
	if(n < 0)
		x = 1 / x;
	bool neg = (x < 0);
	x = fabs(x);

	return (neg ? -1 : 1) * (n < 0 ? 1.0 / myPowAux(x, index) :  myPowAux(x, index));
}

int main()
{
	return 1;
}
