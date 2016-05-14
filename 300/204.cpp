#include <iostream>
#include <unordered_set>
using namespace std;

int countPrimes(int n) {
        int num = 0;
	if(n < 2)
		return num;

	unordered_set<int> composites;
	for(int i = 2; i < n; ++i)
	{
		if(compistes.find(i) == composites.end())
		{
			++num;
			for(int j = 2; j * i <= n; ++j)
				composites.insert(i * j);
		}
	}

	return num;
}

int main()
{
	return 1;
}
