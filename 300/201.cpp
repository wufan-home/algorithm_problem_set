#include <iostream>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
        return (m < n ? rangeBitwiseAnd(m >> 1, n >> 1) << 1 : m);
}

int main()
{
	cout << rangeBitwiseAnd(8, 10) << endl;
}
