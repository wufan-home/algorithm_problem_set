/**/

#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes)
{
	if(n <= 1)
		return n;

	vector<int> index(primes.size(), 0);
	vector<int> rv(1, 1);
	for(int i = 1; i < n; ++i)
	{
		int next_value = INT_MAX;
		int next_index = INT_MAX;
		for(int j = 0; j < primes.size(); ++j)
		{
			int new_value = primes[j] * rv[index[j]];
			if(new_value <= *(rv.end() - 1))
			{
				++index[j];
				new_value = primes[j] * rv[index[j]];
			}
			
			if(new_value < next_value)
			{
				next_value = new_value;
				next_index = j;
			}
		}
		rv.push_back(next_value);
		++index[next_index];
	}

	return rv[n - 1];
}

bool DecompTest(int num, vector<int>& primes)
{
	if(find(primes.begin(), primes.end(), num) != primes.end())
		return true;

	while(num > 1)
	{
		bool has_factor = false;
		for(int i = 0; i < primes.size(); ++i)
		{
			if(num % primes[i] == 0)
			{
				num /= primes[i];
				has_factor = true;
				break;
			}
		}
		if(!has_factor)
			return false;
	}
	return true;
}

int main()
{
	vector<int> primes({2,3,7,13,17,23,31,41,43,47});

	for(int i = 45; i <= 45; ++i)
		cout << i << ": " << nthSuperUglyNumber(i, primes) << endl;

	vector<int> test;
	test.push_back(1);
	for(int i = 2; i <= 82; ++i)
	{
		if(DecompTest(i, primes))
			test.push_back(i);
	}

	for(int i = 0; i < test.size(); ++i)
		cout << test[i] << ", ";
	cout << endl;
	return 1;
}
