/*
   Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <iostream>
#include <vector>

using namespace std;

void GetComb(vector<int>& comb, int start, int n, int k, vector<vector<int> >& combs)
{
	for(int i = start; i <= n; ++i)
	{
		comb.push_back(i);
		if(k == 1)
			combs.push_back(comb);
		else
			GetComb(comb, i + 1, n, k - 1, combs);
		comb.erase(comb.end() - 1);
	}
}

vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > combs;
	if(n * k == 0 || k > n)
		return combs;

	vector<int> comb;
	GetComb(comb, 1, n, k, combs);
	return combs;
}

int main()
{
	vector<vector<int> > r = combine(4, 2);
	for(int i = 0; i < r.size(); ++i)
	{
		for(int j = 0; j < r[i].size(); ++j)
		{
			cout << r[i][j] << ", ";
		}
		cout << endl;
	}
	return 1;
}
