// 50.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double MyPowAux(double x, long long n)
{
	if (n == 1)
		return x;

	return MyPowAux(x * x, n / 2)  * (n % 2 ? x : 1);
}

double myPow(double x, int n)
{
	if (n == 0)
		return 1;

	if (x == 0  || x == 1 || n == 1)
		return x;

	bool neg = (x < 0);
	x = fabs(x);
	long long index = n;
	if (index < 0)
	{
		index = -1 * index;
		x = 1 / x;
	}

	return (neg ? -1 : 1) * MyPowAux(x, index);
}

int main()
{
	cout << myPow(2.000000, INT_MIN) << endl;
    return 0;
}

